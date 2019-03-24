#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maxArea (int* height , int heightSize) {
	int left = 0 , right = heightSize - 1 , max = 0 , capacity , tall;
	while ( left<right ) {
		tall = height [left]<height [right] ? height [left] : height [right];
		capacity = tall*(right - left);
		max = max>capacity ? max : capacity;
		if ( tall == height [left] ) {
			left++;
		}
		else {
			right--;
		}
	}
	return max;
}

int maxArea_stupid (int* height , int heightSize) {
	int tall = 0 , len = 0 , max = 0;
	for ( int i = 0; i<heightSize; i++ ) {
		for ( int j = i + 1; j<heightSize; j++ ) {
			tall = height [i]<height [j] ? height [i] : height [j];
			len = j - i;
			int capacity = tall*len;
			max = max>capacity ? max : capacity;
		}
	}
	return max;
}

int main () {
	int height[] = { 1 , 8 , 6 , 2 , 5 , 4 , 8 , 3 , 7 };
	int heightSize = sizeof (height) / sizeof (height [0]);
	printf ("%d\n" , maxArea (height , heightSize));
	system ("pause");
	return 0;
}