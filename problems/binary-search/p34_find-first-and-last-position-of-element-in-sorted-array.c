/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret_arr = (int*)malloc( 2 * sizeof(int));
    int left = 0, right = numsSize-1, mid = 0;
    *returnSize = 2;
    ret_arr[0] = -1;
    ret_arr[1] = -1;

    if(numsSize == 0) return ret_arr;

    /* O(log n) -> think of Binary search */
    /* find left first */
    while(left < right){
        mid = left + (right - left)/2;
        if( nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }

    /* Check found it or not. */
    if(nums[left] == target){
        ret_arr[0] = left;
    }else{
        return ret_arr;
    }

    /* Then go for right */
    right = numsSize-1;
    
    while(left + 1 < right){
        mid = left + (right - left)/2; 
        if(nums[mid] <= target){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    if(nums[left] == target) ret_arr[1] = left;
    if(nums[right] == target) ret_arr[1] = right;
    return ret_arr;
}
