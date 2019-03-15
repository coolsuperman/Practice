#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	if (!numsSize) { return 0; }
	int end = numsSize - 1;
	int start = 0;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid]<target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (nums[mid]>target) {
		return mid;
	}
	return mid + 1;
}

int main() {
	int arr[] = { 1,2,3,5,8,9 };
	int target = 7;
	int numsSize = sizeof(arr) / sizeof(arr[0]);
	printf("%d", searchInsert(arr, numsSize, target));
	system("pause");
	return 0;
}