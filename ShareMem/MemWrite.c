#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<sys/shm.h>

#define my_key 0x199805

int MemShare(const char* data){
  int handle = shmget(my_key,1024,IPC_CREAT|0664);
  if(handle<0){
    perror("shmget error");
    return -1;
  }
  void* addr = shmat(handle,NULL,0);
  if(addr==(void*)-1){
    perror("shmat error");
    return -1;
  }
  int i = 1;
  int j = 10;
  while(j--){
    sprintf((char*)addr,"hsahahhd+%d\n",i++);
    sleep(1);
  }
  shmdt(addr);
  shmctl(handle,IPC_RMID,NULL);
  return 0;
}

int main(int argc,char* argv[]){
  char data[] = {0};
  //scanf("%s",data);
  MemShare(data);
  return 0;
}
