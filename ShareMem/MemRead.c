#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<sys/shm.h>
#include<string.h>

#define my_key 0x199805

int MemShareRead(){
  int handle = shmget(my_key,1024,IPC_CREAT|0664);
  if(handle<0){
    perror("shmget error");
    return -1;
  }
  char* addr = (char*)shmat(handle,NULL,SHM_RDONLY);
  if(addr==(void*)-1){
    perror("shmat error");
    return -1;
  }
  char*start = "";
  char history[1024] = "";
  while(1){
    if((!strcmp(addr,history))&&strcmp(start,history))//add与上一次输入一直想等，且不为初始值时就说明写段已经关闭了，此时退出；
      break;    
    printf("%s",addr);
    strcpy(history,addr);
    sleep(1);
  }
  shmdt(addr);
  shmctl(handle,IPC_RMID,NULL);
  return 0;
}

int main(int argc,char* argv[]){
  MemShareRead();
  return 0;
}
