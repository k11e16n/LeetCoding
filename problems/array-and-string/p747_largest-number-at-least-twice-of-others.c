int dominantIndex(int* nums, int numsSize) {
    int index = 0;
    for(int i = 0; i < numsSize; i++ ){
        if(nums[index] < nums[i]){
            index = i;
        }
    }
    for(int i = 0; i < numsSize; i++ ){
        if(i != index && nums[index] < 2 * nums[i]){
            return -1;
        }
    }
    return index;
}
