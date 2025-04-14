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
