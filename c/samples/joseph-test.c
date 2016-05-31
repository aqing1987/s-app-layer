#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int no;
    struct node *next;
} node_t, *linklist;

/*
 * n - total node
 * m - steps
 */ 
void joseph(linklist tail, int n, int m)
{
    linklist p = NULL, q = NULL;
    int k = 0, i = 0, old_m = m;

    if (tail == NULL) {
        printf("invalid tail\n");
        return;
    }

    p = tail;
    for (i = n; i > 1; i--)
    {
          // if m > i, m will be changed
        m = m % i;
        if (m == 0) {
            m = i;
        }

          // find the m-1 'th node
        k = 0;
        while (k < m - 1) {
            p = p->next;
            k++;
        }

          // del the m 'th node
        printf("%d\n", p->next->no);
        q = p->next;
        p->next = q->next;
        free(q);

          // restore m to the step
        m = old_m;
    }

    printf("%d\n", p->no);
}

// create cyclic list
linklist create_list(int n)
{
    linklist head = NULL, p = NULL;
    int i;

    if (n < 1) {
        printf("invalid param\n");
        return NULL;
    }
    
    head = (linklist)malloc(sizeof(node_t));
    if (head == NULL) {
        printf("malloc fail.\n");
        return head;
    }

    head->no = 1;
    head->next = head;

      // add the last node first
    for (i = n; i > 1; i--) {
        p = (linklist)malloc(sizeof(node_t));
        if (p == NULL) {
            printf("malloc child node fail\n");
            return head;
        }
        p->no = i;
        p->next = head->next;
        head->next = p;
    }

    return head;
}

void output(linklist head)
{
    linklist p = NULL;

    if (head == NULL) {
        printf("%s head null\n", __func__);
        return;
    }
    
    p = head;
    do {
        printf("%d ", p->no);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main(int argc, char *argv[])
{
    linklist head = NULL;

    head = create_list(10);

    if (head) {
        output(head);
        joseph(head, 10, 3);    
    }
    
    return 0;
}
