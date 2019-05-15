#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int Ticket = 200;//假设一共有100张票;
pthread_mutex_t ticket_lock;//初始化互斥锁；
int count[4] = {0};

void* TicketGrabbing(void * argv){ 
  while(1){
    long i = (long)argv;
    usleep(100*(Ticket*100));
    pthread_mutex_lock(&ticket_lock);//判断前先加锁；
      if(Ticket>0){
        printf("GrabbingRobot No:%ld catch Ticket No:%d\n",i+1,Ticket);
        Ticket--;
        count[i]++;
        pthread_mutex_unlock(&ticket_lock);
      }else{
        printf("No Ticket!,Robot No:%ld Get %d  exit!\n",i+1,count[i]);
        pthread_mutex_unlock(&ticket_lock);
        pthread_exit(NULL);
        //retrun;不可以随便退出，主线程retrun直接进程就推出了！！！
      }
  }
  return NULL;
}

int main(){
  int i;
  pthread_t tpid[4];
  pthread_mutex_init(&ticket_lock,NULL);
  for(i = 0;i<4;i++){
    int  check = pthread_create(&tpid[i],NULL,TicketGrabbing,(void*)i);
    if(check)  
      printf("pthread_create error\n");
  }
  for( i = 0;i<4;i++){
    pthread_join(tpid[i],NULL);//进程等待四个robot线程都运行完再退出；
  }
  pthread_mutex_destroy(&ticket_lock);
  return 0;
}

