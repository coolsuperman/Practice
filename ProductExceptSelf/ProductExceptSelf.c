#include<stdio.h>
#include<stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
      *returnSize = numsSize;
      int* back = (int *)malloc(sizeof(int)*numsSize);
      int i = 0,j = 0;
      back[0]= 1;
      for(i= 1;i<numsSize;i++){
           back[i] = back[i-1]*nums[i-1];               
      }
      for(i = numsSize-2,j= 1;i>=0;--i){
          j*=nums[i+1];
          back[i] *=j;                        
       }
      return back;
}

int main(){
  int nums[]={1,2,3,4,5,6,7};
  int numsSize = sizeof(nums)/sizeof(nums[0]);
  int returnSize = 0;
  int go = 0;
  int* result =  productExceptSelf(nums,numsSize,&returnSize);
  for(go=0;go<returnSize;go++){
    printf(" %d ",result[go]);
  }
  printf("\n");
  free(result);
  return 0;
}

