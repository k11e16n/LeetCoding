bool checkIfExist(int* arr, int arrSize) {
    /* -1000*2 <= arr[i] <= 1000*2 plus zero */
    int map[4001]={0}, zeroCnt=0;

    /* Build the map */
    for(int i = 0; i<arrSize; i++){
        /* the reason add 2000 is:
         * we put 0 as the middle of position
         * So that he negative index works
         */
        map[arr[i]+2000]=1;
    }

    /* Do the Search */
    for(int i=0; i<arrSize; i++){
        /* Specialize zero case */
        if(arr[i]==0){
            zeroCnt++;
            if(zeroCnt>1){
                return true;
            }
        }else if(map[arr[i]*2+2000]==1){
            return true;
        }
    }
    return false;
}
