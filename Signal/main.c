#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

struct sigaction act,old;

void sigcb(int signo){
  printf("recv a signal:%d\n",signo);
  sigaction(signo,&old,NULL);
}

int main(int argc,char* argv[]){
  act.sa_handler = sigcb;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGINT,&act,&old);
  while(1){
    printf("hi\n");
    sleep(1);
  }
  return 0;
}
