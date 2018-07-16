
#include <cstdio>
#include <cstddef>

bool duplicate(int numbers[], int length, int* duplication) {
    //输入合法检测
    if(numbers == NULL || length <= 0) {
	return false;
    }
    for(int i = 0; i < length; i++) {
	if(numbers[i] < 0 || numbers[i] > length - 1)
	    return false;
    }

    //检查是否有重复数字
    for(int i = 0; i < length; i++) {
	while(numbers[i] != i) {
	    if(numbers[i] == numbers[numbers[i]]) {
		*duplication = numbers[i];
		return true;
	    }

	    //交换,注意这容易写错
	    int tmp = numbers[i];
	    numbers[i] = numbers[tmp];
	    numbers[tmp] = tmp;
	}
    }

    return false;
}


int main() {
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    int number2[] = {2, 3, 1, 0, 4, 5, 6};

    //无效输入测试用例
    int number3[] = {2, 3, 1, 0, 7, 5, 3};
    int number4[] = {2, 3, 1, 0, 7, 5, -2};
    
    int dup;
    bool ret;
    ret = duplicate(number3, sizeof(numbers)/sizeof(int), &dup);
    if(ret) {
	printf("Duplicate number is %d\n", dup);
    } else {
	printf("Duplicate number not exit\n");
    }

    return 0;
}
