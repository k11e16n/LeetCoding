void moveZeroes(int* nums, int numsSize) {
    int i=0, j=0;

    for(int i=0; i<numsSize; i++){
        if(nums[i]==0){
            j=i;
            while(j<numsSize && nums[j]==0){
                j++;
            }
            if(j==numsSize){
                break;
            }
            nums[i]=nums[j];
            nums[j]=0;
        }
    }
}
