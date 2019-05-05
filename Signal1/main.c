#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main(){
  int count = 0;
  int flag = 0;
  scanf("%d",&flag);
  while(count++!=100){
    printf("hehe%d\n",count);
    sleep(1);
    if(count==flag){
      raise(SIGQUIT);
    }
  }
  return 0;
}
