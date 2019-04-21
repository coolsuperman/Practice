#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<stdlib.h>

int Write(){
  char* path = "../test.fifo";
  umask(0);
  int ret = mkfifo(path,0660);
  if(errno!=EEXIST&&ret!=0){
    perror("mkfifo error");//搞清楚为啥这么秀
    exit(-1);
  }
  printf("prepare to openning file!\n");
  int handle = open(path,O_WRONLY|O_TRUNC);
  if(handle<0){
    perror("open error");
    return -1;
  }
  printf("open file sucess!\n");
  int count = 10;
  char* num[] = {"一号第10次写入","一号第9次写入","一号第8次写入","一号第7次写入","一号第6次写入","一号第5次写入","一号第4次写入","一号第3次写入","一号第2次写入","一号第1次写入"};
  while(count--)
  {
    sleep(3);
    char test[100] = "这是一个通信测试文本~~";
    strcat(test,num[count]);
    write(handle,test,strlen(test));
  }
  close(handle);
  return 0;
}


int main(){
  Write();
  return 0;
}
