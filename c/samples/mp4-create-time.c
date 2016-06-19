#include <stdio.h>
#include <time.h>
#include <arpa/inet.h>

// according to ISO/IEC 14496-12 mp4 creation_time is an integer that
// declares the creation time of the media in this track (in seconds since
// midnight, Jan. 1, 1904, in UTC time)
unsigned int GetDateSeconds()
{
    time_t t_utc_1970 = 0;
    unsigned int seconds_from_1904 = 0;
    struct tm *tblock;

    // time() returns the time as the number of seconds
    // since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
    time(&t_utc_1970);
    printf("seconds from 1970 is %ld\n", t_utc_1970);

    // there are 2082844800 seconds from 1904.1.1 to 1970.1.1
    // attention: there are leap years from 1904 to 1970
    seconds_from_1904 = t_utc_1970 + 2082844800;
    printf("seconds from 1904 is %u\n", seconds_from_1904);

    t_utc_1970 = seconds_from_1904;
    tblock = localtime(&t_utc_1970);
    printf("Local time is: %s\n", asctime(tblock));

    return htonl(seconds_from_1904);
}

int main(int argc, char *argv[])
{
    GetDateSeconds();

    return 0;
}

