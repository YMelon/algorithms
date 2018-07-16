
#include <iostream>
#include <cstdio>

int countRange(const int* numbers, int length, int start, int end) {
    //错误处理
    if(numbers == NULL)
	return 0;

    int count = 0;
    for(int i = 0; i < length; i++) {
	if(numbers[i] >= start && numbers[i] <= end)
	    count ++;
    }
    return count;

}
int getDuplication(const int* numbers, int length) {
    //检测输入合法
    if(numbers == NULL || length <= 0)
	return -1;

    int start = 1;
    int end = length - 1;
    while(end >= start) {
	int middle = (start + end) / 2;
	int count = countRange(numbers, length, start, middle);
	if(end ==start) {
	    if(count > 1) //找到了
		return start;
	    else
		break;
	}

	if(count > (middle - start + 1))
	    end = middle;
	else
	    start = middle + 1;
    }

    return -1;
}


int main() {
    int n1[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int n2[] = {3, 2, 1, 4, 4, 5, 6, 7};
    int n3[] = {1, 2, 3, 4, 5, 6, 7, 1, 8};
    int n4[] = {1, 7, 3, 4, 5, 6, 8, 2, 8};
    int n5[] = {1, 1};
    int n6[] = {1, 2, 2, 6, 4, 5, 2};
    int n7[] = {1, 2, 6, 4, 5, 3};

    int ret = getDuplication(n7, sizeof(n7) / sizeof(int));
    if(ret > 0)
	printf("Duplicate num is %d\n", ret);
    else
	printf("No duplicate num exit\n");

    return 0;
}





