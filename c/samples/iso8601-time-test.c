#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer, 80, "%Y-%m-%dT%H:%M:%S%z",timeinfo);
  puts (buffer);
  
  return 0;
}
