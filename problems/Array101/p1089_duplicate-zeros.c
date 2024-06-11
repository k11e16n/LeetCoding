void duplicateZeros(int* arr, int arrSize) {
    int bigArr[20000]={0}, arrCnt=0, bigArrCnt=0;
    while(arrCnt<arrSize){
        if(arr[arrCnt]==0){
            bigArr[bigArrCnt]=0;
            bigArrCnt++;
            bigArr[bigArrCnt]=0;
        }else{
            bigArr[bigArrCnt]=arr[arrCnt];

        }
        arrCnt++;
        bigArrCnt++;
    }

    for(int i=0; i<arrSize; i++){
        arr[i]=bigArr[i];
    }
}
