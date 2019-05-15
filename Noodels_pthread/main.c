#include<stdio.h>

#include<unistd.h>
#include<pthread.h>

int noodle = 0;
int count = 0;
int max = 100;
pthread_mutex_t lock;
pthread_cond_t client;//客人条件变量
pthread_cond_t cooker;//厨师条件变量

void* Eat(void* arg){
  while(1){
    pthread_mutex_lock(&lock);//保护noodle只有一个线程操作
    while(!noodle){//if->while防止伪唤醒，多个客人线程被唤醒，其他客人线程吃碗面解锁后，此线程没有继续判断有面没面就开吃了；
      pthread_cond_wait(&client,&lock);//解锁》唤醒》加锁；
      if(count==max){//做了100碗面了，客人线程退出，并唤醒一个厨师线程下班
        printf("NO:%ld set no clint come in!\n",(long)arg);
        pthread_cond_signal(&cooker);
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
      }
    }
    printf("clint NO:%ld eat noodle!\n",(long)arg);
    noodle = 0;
    pthread_cond_signal(&cooker);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}
void* Make(void* arg){
  while(1){
    pthread_mutex_lock(&lock);
    while(noodle){//同理，防止伪唤醒
      pthread_cond_wait(&cooker,&lock);
      if(count==max){//已经到达了目标碗面了，一个厨师下线，唤醒一个客人线程不再产生客人；
        printf("At night resturant close,No:%ld out!\n",(long)arg);
        pthread_cond_signal(&client);
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
      }
    }
    printf("cooker No:%ld make noodle!\n",(long)arg);
    noodle = 1;
    count++;
    printf("has cooked: %d\n",count);
    pthread_cond_signal(&client);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(){
  pthread_t etid[4],mtid[4];
  pthread_mutex_init(&lock,NULL);
  pthread_cond_init(&client,NULL);
  pthread_cond_init(&cooker,NULL);
  int i ,ret;
  for(i = 0;i<4;i++){
    ret = pthread_create(etid+i,NULL,Eat,(void*)i);
    if(ret){
      printf("Eat pthread create error!\n");
      return -1;
    }
  }
  for(i = 0;i<4;i++){
    ret = pthread_create(mtid+i,NULL,Make,(void*)i);
    if(ret){
      printf("Make pthread creat error!\n");
      return -1;
    }
  }
  for(i = 0;i<4;i++){
    pthread_join(etid[i],NULL);
    pthread_join(mtid[i],NULL);
  }
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&client);
  pthread_cond_destroy(&cooker);
  return 0;
}
