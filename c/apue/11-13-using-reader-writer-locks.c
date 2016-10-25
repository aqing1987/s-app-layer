/**
 * A queue of job request is protected by a single reader-writer
 * lock.
 * multiple worker threads obtain jobs assigned to them by a single
 * master thread.
 * we lock the queue's reader-writer lock in write mode whenever we
 * need to add a job to the queue or remove a job from the queue.
 * Whenever we search the queue, we grab the lock in reader mode,
 * allowing all the worker threads to search the queue concurrently.
 * Using a reader-writer lock will improve performance in this case
 * only if threads search the queue much more frequently than they
 * add or remove jobs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct job {
    struct job *j_next;
    struct job *j_prev;
    pthread_t j_id; // tells which thread handles this job
};

struct queue {
    struct job *q_head;
    struct job *q_tail;
    pthread_rwlock_t q_lock;
};

struct queue g_task_queue;

/**
 * initialize a queue
 */
static int queue_init(struct queue *qp)
{
    int err;

    qp->q_head = NULL;
    qp->q_tail = NULL;
    err = pthread_rwlock_init(&qp->q_lock, NULL);
    if (err != 0) {
        return err;
    }

    return 0;
}

/**
 * insert a job at the head of the queue
 */
static void job_insert(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    jp->j_next = qp->q_head;
    jp->j_prev = NULL;
    if (qp->q_head != NULL) {
        qp->q_head->j_prev = jp;
    } else {
        qp->q_tail = jp; // list was empty
    }
    qp->q_head = jp;
    pthread_rwlock_unlock(&qp->q_lock);
}

/**
 * append a job on the tail of the queue
 */
static void job_append(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    jp->j_next = NULL;
    jp->j_prev = qp->q_tail;
    if (qp->q_tail != NULL) {
        qp->q_tail->j_next = jp;
    } else {
        qp->q_head = jp; // list was empty
    }
    qp->q_tail = jp;
    pthread_rwlock_unlock(&qp->q_lock);
}

/**
 * remove the given job from a queue
 */
static void job_remove(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    if (jp == qp->q_head) {
        qp->q_head = jp->j_next;
        if (qp->q_tail == jp) {
            qp->q_tail = NULL;
        }
    } else if (jp == qp->q_tail) {
        qp->q_tail = jp->j_prev;
        if (qp->q_head == jp) {
            qp->q_head = NULL;
        }
    } else {
        jp->j_prev->j_next = jp->j_next;
        jp->j_next->j_prev = jp->j_prev;
    }
    pthread_rwlock_unlock(&qp->q_lock);
}

/**
 * find a job for the given thread ID.
 */
static struct job *job_find(struct queue *qp, pthread_t id)
{
    struct job *jp;

    if (pthread_rwlock_rdlock(&qp->q_lock) != 0) {
        return NULL;
    }

    int i = 0;
    for (jp = qp->q_head; jp != NULL; jp = jp->j_next) {
        i++;
    }
    printf("total jobs = %d\n", i);

    for (jp = qp->q_head; jp != NULL; jp = jp->j_next) {
        if (pthread_equal(jp->j_id, id)) {
            break;
        }
    }

    pthread_rwlock_unlock(&qp->q_lock);
    return jp;
}

static void *thr_fn1(void *arg)
{
    printf("thread 1 start\n");

    struct job f1_job;
    f1_job.j_id = pthread_self();
    job_insert(&g_task_queue, &f1_job);

    int i = 0;

    struct job *pf = NULL;
    for (i = 0; i < 100; i++) {
        pf = job_find(&g_task_queue, pthread_self());
        if (pf) {
            printf("find %ul\n", pthread_self());
        }
        sleep(1);
    }

    printf("thread 1 end\n");
    return ((void *)1);
}

static void *thr_fn2(void *arg)
{
    printf("thread 2 start\n");

    struct job f2_jobs[100];
    int i = 0;

    for (i = 0; i < 100; i++) {
        f2_jobs[i].j_id = pthread_self();
        job_insert(&g_task_queue, &f2_jobs[i]);
        sleep(2);
    }

    printf("thread 2 end\n");
    pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = queue_init(&g_task_queue);
    if (err != 0) {
        printf("queue init err");
        return -1;
    }

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        perror("create thread 1");
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        perror("create thread 2");
    }

    err = pthread_join(tid1, &tret);
    if (err != 0) {
        perror("join thread 1");
    }
    printf("thread 1 exit code %d\n", (int)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0) {
        perror("join thread 2");
    }
    printf("thread 2 exit code %d\n", (int)tret);

    return 0;
}
