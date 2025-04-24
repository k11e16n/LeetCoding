int search(int* nums, int numsSize, int target) {
    /* Note:
    *  Find a pivot and make it a non-shifted array will take O(N)
    *  which is fail to meet the require of the question.
    *  Instead, we need to deal with Binary search and order at the same time.
    */

    int left = 0, right = numsSize - 1, mid = 0;

    while(left <= right){
        /* Get mid */
        mid = left + (right - left)/2;
        if( nums[mid] == target ){
            return mid;
        /* We not only seek for target but try to find a ascending range */
        }else if(nums[left] <= nums[mid]){ /* this means left side of mid are ascending */
            /* next we check is target in it or not.
            *  It should be nums[left] "<="" target, because the target might be "left"
            *  what about nums[mid]? it already compared!
            */
            if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }else{ /* If not then it must be another side */
                left = mid + 1;
            }
        }else{
            /* same alog. */
            /* It should be target "<="" nums[right], because the target might be "right" */
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }else{ 
                right = mid - 1;
            }
        }
    }

    return -1;
}
