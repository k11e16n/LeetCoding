int compare( const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int split_number_with_mid(int* nums, int numsSize, int Allowd_Num){
    int count = 1 /* at least one subarray */, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if( sum + nums[i] <= Allowd_Num){
            sum += nums[i];
        }else{
            count++;
            sum = nums[i];
        }
    }
    return count;
}

int splitArray(int* nums, int numsSize, int k) {
    /* Answer will be in the range from Left:max(nums) ~ Right:sum(nums)
     * Using BS, test with mid as anser, check it could be split into k or not.
     */
    int left = 0, right = 0, mid = 0;
    for(int i=0; i<numsSize; i++){
        if(left < nums[i]) left = nums[i];
        right += nums[i];
    }

    while( left < right ){
        mid = left + (right - left)/2;
        if( split_number_with_mid(nums, numsSize, mid) <= k ){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return left;
}
