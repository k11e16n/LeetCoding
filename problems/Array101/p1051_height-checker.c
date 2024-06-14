void mergesort(int * a,int len){
    if(len <= 1)
        return;

    int mid = len/2;
    //sort front half
    mergesort(a, mid);
    //sort back half
    mergesort(a+mid, len - mid);
    //new sorted array
    int * temp = (int*)malloc(sizeof(int)*len);

    int fp = 0, bp = mid;

    for(int i = 0; i < len; i++){
        if((fp >= mid) || ((bp < len) && (a[bp] <= a[fp]))){
            temp[i] = a[bp];
            bp++;
        }else{
            temp[i] = a[fp];
            fp++;
        }
    }
    //move temp array to array
    for(int i = 0; i < len; i++){
        a[i] = temp[i];
    }
    free(temp);

}

int heightChecker(int* heights, int heightsSize) {
    int count=0;
    int *oriArr=malloc(heightsSize * sizeof(int));

    /* Back up the original */
    memcpy(oriArr, heights, heightsSize*sizeof(int));


    /* Sort it first */
    mergesort(heights, heightsSize);

    /* Selection sort
    for(int i=0; i<heightsSize; i++){
        for(int j=i; j<heightsSize; j++){
            int temp;
            if(heights[j]<heights[i]){
                temp=heights[j];
                heights[j]=heights[i];
                heights[i]=temp;
            }
        }
    }
    */

    /* Compare to get the count */
    for(int i=0; i<heightsSize; i++){
        if(oriArr[i]!=heights[i]){
            count++;
        }
    }

    free(oriArr);
    return count;
}
