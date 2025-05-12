int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize-1, mid = 0;
    while(left < right){
        mid = left + (right - left)/2;
        // if mid == right: the right won't be the answer so we skip it.
        if( nums[mid] == nums[right]){
            right--;
        // the rest we could follow the idea in #153
        }else if( nums[mid] < nums[right]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return nums[left];
}
