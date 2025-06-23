 #define METHOD 1
#if METHOD == 1 // divide and conquer
/* Main idea:
 * Find a mid, compare below
 * 1. Max left = maxSubArray(nums, left, mid)
 * 2. Max right = maxSubArray(nums, mid+1, right)
 * 3. Max cross = include mid
 */

int max(int a, int b){
    return (a>b)?a:b;
}

int max_for_3(int a, int b, int c){
    return max( max(a, b) ,c);
}

int my_maxSubArray(int* nums, int numsSize, int left, int right){
    /* Consider border condition */
    if( left == right) return nums[left];

    /* get Max left and Max right */
    int mid = left + (right - left)/2;
    int left_max = my_maxSubArray(nums, numsSize, left, mid);
    int right_max = my_maxSubArray(nums, numsSize, mid+1, right);

    /* get cross Max */
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

    /* Get left */
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if( sum > leftSum){
            leftSum = sum;
        }
    }

    /* Get right */
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if( sum > rightSum){
            rightSum = sum;
        }
    }

    /* return the max */
    return max_for_3( left_max, right_max, (leftSum + rightSum));
}

int maxSubArray(int* nums, int numsSize){
    return my_maxSubArray(nums, numsSize, 0, numsSize-1);
}
#endif

#if METHOD == 2 // O(n) method
/* Main idea:
 * current_max = max(nums[i], current_max + nums[i])
 * global_max = max(global_max, current_max)
 */
int maxSubArray(int* nums, int numsSize) {
    int global_max = -10001, curr_max = -10001;
    for(int i = 0; i < numsSize; i++){
        if((curr_max + nums[i]) > nums[i]){
            curr_max += nums[i];
        }else{
            curr_max = nums[i];
        }

        /* Update global*/
        if(curr_max >= global_max){
            global_max = curr_max;
        }
    }

    return global_max;
}
#endif
