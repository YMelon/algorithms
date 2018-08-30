
int Partion(int data[], int length, int start, int end) {
    if(data == NULL || length <= 0 || start < 0 || end >= length){
	printf("Invalid input\n");
	return -1;
    }

    int index = random(start, end);
    swap(&data[indext], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index) {
    //小于基准的元素放到前半部分，大于基准的放到后半部分
	if(data[index] < data[end]) {
	    ++ small;
	    if(small != index)
		swap(&data[index], &data[small]);
	}
    }

    ++ small;
    swap(&data[small], &data[end]);

    return small;
}


void QuickSort(int data[], int length, int start, int end) {
    if(start == end)
	return;

    int index = Partion(data, length, start, end);

    if(index > start)
	QuickSort(data, length, start, index-1);
    if(index < end)
	QuickSort(data, length, index+1, end);
}
