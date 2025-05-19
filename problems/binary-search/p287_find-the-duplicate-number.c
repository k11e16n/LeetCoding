#define METHOD 2

#if METHOD == 1 // bitset
int findDuplicate(int* nums, int numsSize) {
    int* map = malloc( numsSize * sizeof(int));
    memset( map, 0, numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        map[nums[i]]++;
        if( map[nums[i]] == 2){
            free(map);
            return nums[i];
        }
    }
    free(map);
    return -1;
}
#endif

#if METHOD == 2 // binary search
int number_of_element_less_equal_than_target(int* nums, int numsSize, int target){
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if( nums[i] <= target){
            count++;
        }
    }
    return count;
}

int findDuplicate(int* nums, int numsSize) {
    int left = 1, right = numsSize - 1; // 1 <= nums[i] <= n
    int mid = 0;

    while( left < right ){
        mid = left + (right - left)/2;
        if( number_of_element_less_equal_than_target(nums, numsSize, mid) > mid){
            /* number of elements bigger than mid then it must has duplicate. */
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
#endif
