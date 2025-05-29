int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int num_of_pair_less_than_max(int* nums, int numsSize, int max){
    int count = 0;
    int left = 0;
    for(int right = 0; right < numsSize; right++){
        // find a left so that every element within are <= max
        while( nums[right] - nums[left] > max){ 
            /* Q: Why the position left no need to start from 0?
             * A: Array is "sorted", if previous right - left is greater than max,
             *    While right become bigger(move right), previous left is impossible < max
             */
            left++;
        }
        /* legal number for current right, accumulate it */
        count += right - left;
    }
    return count;
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0, right = nums[numsSize - 1] - nums[0], mid = 0;

    while( left <= right ){
        mid = left + (right - left) / 2;
        if( num_of_pair_less_than_max(nums, numsSize, mid) >= k){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

   return left;
}
