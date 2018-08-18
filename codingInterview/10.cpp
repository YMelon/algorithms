#include <stdio.h>

long long FibonacciR(unsigned int n) {
    if(n <= 0)
	return 0;
    if(n == 1)
	return 1;

    return FibonacciR(n-1) + FibonacciR(n-2);
}

long long Fibonacci(unsigned int n) {
    int ret[2] = {0, 1};
    if(n < 2)
	return ret[n];

    long long fibOne = 1;
    long long fibTwo = 0;
    long long fibN = 0;
    for(int i = 2; i <= n; ++ i) {
	fibN = fibOne + fibTwo;
	fibTwo = fibOne;
	fibOne = fibN;
    }

    return fibN;
}

int main(int argc, const char* argv[]) {
    unsigned int n;
    scanf("%u", &n);
    //long long ret = FibonacciR(n);
    long long ret = Fibonacci(n);
    printf("Fibonacci sum is: %lld\n", ret);

    return 0;
}
