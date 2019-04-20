#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>

void Pipe(){
  int pipefd[2];
  int ret = pipe(pipefd);
  if(ret<0){
    perror("pipe error");
    exit(-1);
  }
  int pid = fork();
  if(pid<0){
    printf("fork error");
    exit(-1);
  }else if(pid==0){
    close(pipefd[1]);
    char buf[1024] = {0};
    int ret = read(pipefd[0],buf,1023);
    printf("buf:%d-%s\n",ret,buf);
    ret = read(pipefd[0],buf,1023);
    printf("buf:%d-%s\n",ret,buf);
  }else{
    close(pipefd[0]);
    char* src = "这是一个测试句~~";
    write(pipefd[1],src,strlen(src));
    close(pipefd[1]);
    sleep(2);
  }
  return ;
}


int main(){
  Pipe();
  return 0;
}
