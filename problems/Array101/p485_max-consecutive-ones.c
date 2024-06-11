int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int sum=0, max=0;
    for(int i=0; i<numsSize; i++){
        if( nums[i]==1){
            sum++;
            if(max<sum){
                max=sum;
            }
        }else{
            sum=0;
        }
    }
    return max;
}
