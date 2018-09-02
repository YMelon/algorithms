
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
