#define METHOD 2
#if METHOD == 1
int search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize-1, check_pos = 0;
    
    while( start <= end ){
        check_pos = (start + end)/2;
        if( target == nums[check_pos]){
            return check_pos;
        }else if( target > nums[check_pos]){
            start = check_pos+1;
        }else{
            end = check_pos-1;
        }
    }

    return -1;
}
#endif

#if METHOD == 2
int do_search(int* arr, int left, int right, int target){
    if(left > right){
        return -1;
    }
    int mid = (left + right)/2;
    if(target == arr[mid]){
        return mid;
    }else if(target > arr[mid]){
        return do_search(arr, mid+1, right, target);
    }else{
        return do_search(arr, left, mid-1, target);
    }
}

int search(int* nums, int numsSize, int target) {
    return do_search(nums, 0, numsSize-1, target);
}
#endif
