/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int x = 1
void handler(int signum)
{ //signal handler
  x=1;
  printf("Hello World!\n");
  alarm(1);
  x=0;

}

int main(int argc, char * argv[])
{
  for (;;){
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 2 second
  while(x);
      printf("Turing was right!\n");
      x = 1;
  }
  return 0; //never reached
}