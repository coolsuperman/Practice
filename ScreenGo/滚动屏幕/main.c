#include<stdio.h>
#include<windows.h>


int main()
{
    char arr1[] = "This is test for this code!!!";
	char arr2[] = "#############################";
	int left = 0;
	int right = strlen(arr1)-1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		left++;
		right--;
		Sleep(300);
		system("CLS");
	}
	printf("%s\n", arr2);
	system("pause");
	return 0;
}