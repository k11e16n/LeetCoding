#define METHOD 2

#if METHOD == 1
int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize-1, mid = 1;

    while( left < right){
        mid = left + (right - left)/2;

        /* we compare mid with it next one!
        *  Hints said "nums[i] != nums[i + 1] for all valid i."
        *  so we can use it as comparison condition.
        *  mid > mid+1: mid might be peak so change right as mid and compare again next round.
        *  mid < mid+1: mid impossible to be peak, so we skip it next round.
        */
        if(nums[mid] > nums[mid+1]){
            right = mid;
        }else{  /* it won't be equal */
            left = mid + 1;
        }
    }
    return left;
}
#endif

/* rewrite */
#if METHOD == 2 
int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize-1, mid = 1;

    while( left + 1 < right){
        mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return (nums[left] > nums[right])?left:right;

}
#endif
