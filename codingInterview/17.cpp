
void Print1ToMaxOfNDigits(int n) {
    if(n <= 0)
	return;

    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';

    while(!Increment(num)) {
	PrintNum(num);
    }

    delete[] num;
}


bool Increment(char* num) {
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLen = strlen(num);
    for(int i = nLen-1; i >= 0; --i) {
	int nSum = num[i] - '0' + nTakeOver;

	if(i == nLen -1)
	    nSum ++;

	if(nSum >= 10) {
	    if(i == 0)
		isOverflow = true;
	    else {
		nSum -= 10;
		nTakeOver = 1;
		num[i] = nSum + '0';
	    }
	} else {
	    num[i] = '0' + nSum;
	    break;
	}
    }

    return isOverflow;
}

void PrintNum(char* num) {
    bool isBegin0 = true;
    int nLen = strlen(num);

    for(int i = 0; i < nLen; ++i){
	if(isBegin0 && num[i] != '0')
	    isBegin0 = false;

	if(!isBegin0)
	    printf("%c", num[i]);
    }

    printf("\t");
}




//第二种算法
void Print1ToMaxOfNDigits(int n) {
    if(n <= 0)
	return;

    char* num = new char[n+1];
    num[n] = '\0';
    
    for(int i = 0; i < 10; ++i) {
	num[0] = i + '0';
	Print1ToMaxOfNDigitsRecur(num, n, 0);
    }

    delete[] num;
}

void Print1ToMaxOfNDigitsRecur(char* num, int len, int index) {
    if(index == len - 1) {
	PrintNum(num);
	return;
    }

    for(int i = 0; i < 10; ++i) {
	num[index+1] = i + '0';
	Print1ToMaxOfNDigitsRecur(num, len, index+1);
    }
}


