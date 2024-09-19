#define NaN 100001
int minSubArrayLen(int target, int* nums, int numsSize) {
    int l_pos = 0, r_pos = 0, count = 0, sum = 0, min = NaN;

    while( r_pos < numsSize ){
        /* Move right */
        sum += nums[r_pos];

        /* until we found greater than target */
        while( sum >= target ){
            /* we update min if needed */
            if( (r_pos - l_pos + 1)  < min){
                min = (r_pos - l_pos + 1);
            }
            /* Move left */
            sum -= nums[l_pos++];
        }
        r_pos++;
    }

    return (min==NaN)?0:min;
}
