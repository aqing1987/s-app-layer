#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

static int check_record_time(char *str_time, time_t *start_time, time_t *stop_time)
{
    char start_str[32] = {0};
    char stop_str[32] = {0};
    struct tm tm_start;
    struct tm tm_stop;
    struct tm tm_now;
    time_t time_now;
    char * p = NULL;

    p = strstr(str_time, "-");
    if (p == NULL) {
        return -1;
    }

    strncpy(start_str, str_time, p-str_time);
    strncpy(stop_str, p+1, strlen(str_time) - (p-str_time) -1);
    if (strncmp(stop_str, "24:00", 5) == 0) {
        strcpy(stop_str, "23:59");
    }
    time_now = time(NULL);
    printf("time_now = %d\n", (int)time_now);
    localtime_r(&time_now, &tm_now);
    printf("now %d:%d:%d\n", tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);

    tm_start = tm_now;
    tm_stop = tm_now;
    strptime(start_str, "%H:%M", &tm_start);
    strptime(stop_str ,"%H:%M", &tm_stop);

    printf("start time = %s, stop time = %s\n", start_str, stop_str);
    // time_t mktime(struct tm *tm);
    *start_time = mktime(&tm_start);
    *stop_time = mktime(&tm_stop);
    if (*start_time > *stop_time){
        *stop_time += 3600*24;
    }

    if (*stop_time > time_now && time_now > *start_time) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    time_t start_time, stop_time;

    time_t tNow = time(NULL);
    time_t tEnd = tNow + 1800; // after 1800 seconds

    struct tm ptm, ptmEnd;
    // struct tm *localtime_r(const time_t *timep, struct tm *result);
    localtime_r(&tNow, &ptm);
    localtime_r(&tEnd, &ptmEnd);

    char szTmp[50] = {0};
    strftime(szTmp, 50, "%H:%M:%S", &ptm);

    char szEnd[50] = {0};
    strftime(szEnd, 50, "%H:%M:%S", &ptmEnd);

    printf("%s \n", szTmp);
    printf("%s \n", szEnd);

    start_time = 0;
    stop_time = 0;
    sleep(3);
    if (check_record_time("00:00-24:00", &start_time, &stop_time) == 1) {
        printf("time not reached.\n");
    }
    else {
        printf("time reached.\n");
    }
    printf("start time = %d, stop time = %d\n", (int)start_time, (int)stop_time);

    return 0;
}
