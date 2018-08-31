
int maxProduct(int len) {
    if(len < 2)
	return 0;
    if(len == 2)
	return 1;
    if(len == 3)
	return 2;

    int* products = new int[len+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i = 4; i <= len; ++i) {
	max = 0;
	for(int j = 1; j <= i/2; ++j) {
	    int product = products[j]*products[i-j];
	    if(max < product)
		max = product;

	    products[i] = max;
	}
    }

    max = products[len];
    delete[] products;

    return max;
}


//greedy version
int maxProduct(int len) {
    if(len < 2)
	return 0;
    if(len == 2)
	return 1;
    if(len == 3)
	return 2;

    int timesOf3 = len / 3;

    if(len - timesOf3*3 == 1)
	timesOf3 -= 1;

    int timesOf2 = (len - timesOf3*3) / 2;
    
    int res = (int)pow(3, timesOf3) * (int)pow(2, timesOf2);
    return res;
}
