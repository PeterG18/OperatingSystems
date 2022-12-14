#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int randForProcess(){
  srand((time(NULL)*390));
  int randNum = ((rand()%30)+1);//no more than 30 loops
  return randNum;
}

int randForSleep(){
  srand((time(NULL)));
  int randNum = ((rand()%10)+1);// up to 10 seconds
  return randNum;
}

void  main(void)
{
     pid_t  pid1, pid2;

     pid1 = fork();
     if (pid1 == 0){ 
          ChildProcess();
         // ParentProcess();
     }
     else {
       pid2 = fork();
       if (pid2 == 0){
         ChildProcess();
       //  ParentProcess();
       }
     }
     ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= randForProcess(); i++){
             printf("Child Pid: %d is going to sleep!\n", getpid());
             sleep(randForSleep());
             printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
     }
     exit(0);
      //    printf("   This line is from child, value = %d\n", i);
     //printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     wait(NULL);
     int   i;

     printf("Child Pid: %d has completed\n", getpid());

}