#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>


void Pipe(){
  int pipefd[2];
  if(pipe(pipefd)<0){
    printf("pipe error");
    return;
  }
  int pid1 = fork();
  if(pid1<0){
    printf("fork error");
    exit(-1);
  }else if(pid1==0){
    close(pipefd[0]);
    dup2(pipefd[1],1);
    execlp("ls","ls",NULL);
    exit(-1);
  }
  int pid2 = fork();
  if(pid2<0){
    printf("fork error");
    exit(-1);
  }else if(pid2==0){
    close(pipefd[1]);
    dup2(pipefd[0],0);
    execlp("grep","grep","a",NULL);
    return ;
  }
  close(pipefd[0]);
  close(pipefd[1]);
  wait(NULL);
  wait(NULL);
  return;//可以刷新缓冲区吗？
}


int main(){
  Pipe();
  return 0;
}
