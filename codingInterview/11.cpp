
int Min(int* num, int len) {
    if(num == NULL || len <= 0) {
	pringf("Invalid parameters\n");
	return -1;
    }

    int index1 = 0;
    int index2 = len - 1;
    int indexMid = index1;
    while(num[index1] >= num[index2]) {
	if(index2 - index1 == 1) {
	    indexMide = index2;
	    break;
	}

	indexMid = (index1 + index2) / 2;
	if(num[indexMid] >= num[index1])
	    index1 = indexMid;
	else if(num[indexMid] <= num[index2])
	    index2 = indexMid;
    }

    return num[indexMid];
}


//修改版
int Min(int* num, int len) {
    if(num == NULL || len <= 0) {
	printf("Invalid parameter");
	return -1;
    }

    int index1 = 0;
    int index2 = len - 1;
    int indexMid = index1;
    while(num[index1] >= num[index2]) {
	if(index2 - index1 == 1) {
	    indexMid = index2;
	    break;
	}

	indexMid = (index1 + index2) / 2;

	if(num[index1] == num[index2] && num[indexMid] == num[index1])
	    return MinInorder(num, index1, index2);

	if(num[indexMid] >= num[index1])
	    index1 = indexMid;
	else if(num[indexMid] <= num[index2])
	    index2 = indexMid;
    }

    return num[indexMid];
}

int MinInOrder(int* num, int index1, int index2) {
    int result = num[index1];
    for(int i = index1; i <= index2; ++i) {
	if(num[i] < result)
	    result = num[i];
    }

    return result;
}
