#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h> 
#include  <time.h>
#include  <sys/wait.h>
#include  <unistd.h>


int status;

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(int cpid);               /* parent process prototype */

void  main(void)
{
     pid_t  childA, childB;

     srandom(time(0));

     childA = fork();
     if (childA == 0){
          ChildProcess();
     }
     
     childB = fork();
     if (childB == 0){
          ChildProcess();
     }else{
     
          childA = wait(&status);
          ParentProcess(childA);

          childB = wait(&status);
          ParentProcess(childB);
     }
              
}

void  ChildProcess(void)
{
     int   i;
     int num = random() % 31;
     int asleep = random() % 11;

     for (i = 1; i <= num; i++){
          printf("Child Pid: %d is going to sleep!", getpid());
          sleep(asleep);
          printf("Child Pid: %d is awake!\nWhere is my Parent: %d", getpid(), getppid());
     
     }
     exit(0);
}

void  ParentProcess(int cpid)
{
     int   i;

     printf("Child Pid: %d has completed\n", cpid);
     

}
