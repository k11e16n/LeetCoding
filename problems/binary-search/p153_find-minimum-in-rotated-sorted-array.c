int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize-1, mid = 0;
    while(left < right){
        mid = left + (right - left)/2;

        /* Some constraints
        *  1. nums are unique.
        *  2. it's ascending
        *  mid > right: min should be right side
        *  mid < right: min should be left side
        */
 
        if( nums[mid] < nums[right]){ /* check left side, and mid should be check again */
            /* at this point, although mid already be compared,
            *  but it may be answer so need to be compare again.
            */
            right = mid;
        }else{ /* Check right side */
            /* at this point, mid >= right (no equal case here)
            *  it won't be min so no need to compare again.
            */
            left = mid + 1;
        }
    }
    return nums[left];
}
