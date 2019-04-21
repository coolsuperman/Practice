#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

void Pipe(){
  char *path = "../test.fifo";
  umask(0);
  int ret = mkfifo(path,0777);
  if(ret<0&& errno!=EEXIST){
    perror("mkfifo error");
    return ;
  }
  printf("prepare open file fifo\n");
  int handle = open(path,O_RDONLY);
  if(handle<0){
    perror("open error");
    return ;
  }
  printf("open fifo sucess\n");
  int count =1;
  while(1){
    sleep(2);
    char buf[1024] = {0};
    int check = read(handle,buf,1023);
    if(!check)
      break;
    printf("buf:[%d][%d]->%s\n",count,check,buf);
    count++;
  }
  close(handle);
  return;
}

int main(){
  Pipe();
  return 0;
}
