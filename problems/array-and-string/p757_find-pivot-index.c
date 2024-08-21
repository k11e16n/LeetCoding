#define METHOD 2

#if METHOD == 1
int pivotIndex(int* nums, int numsSize) {
    /* Take i as index */
    for(int i = 0; i<numsSize; i++){
        int left_sum = 0, right_sum = 0;
        /* get left sum */
        for(int left = 0; left < i; left++){
            left_sum += nums[left];
        }
        /* get right sum */
        for(int right = numsSize-1; right > i; right--){
            right_sum += nums[right];
        }
        /* Compare and return */
        if(left_sum == right_sum){
            return i;
        }
    }
    return -1;
}
#endif

#if METHOD == 2
int pivotIndex(int* nums, int numsSize) {
    int left_sum = 0, right_sum = 0;

    /* Get total sum first */
    for(int i = 0; i<numsSize; i++){
        right_sum += nums[i];
    }

    for(int i = 0; i<numsSize; i++){
        right_sum -= nums[i];
        if( left_sum == right_sum ){
            return i;
        }
        left_sum += nums[i];
    }

    return -1;
}
#endif
