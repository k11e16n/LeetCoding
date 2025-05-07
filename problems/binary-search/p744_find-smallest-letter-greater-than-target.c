#define TEMPLATE 3

#if TEMPLATE == 1
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize - 1, mid = 0;
    int ans = 0; // No element left after loop, so we need record.
    while( left <= right ){ // This control element amount
        mid = left + (right - left)/2;
        if(letters[mid] > target){ // Main comparion, how we cut the half and remain mid.
        /* in this case, ans is "Next Greater than Target"
        *  so if mid > target, mid might be ans so save it
        */
            ans = mid;
            right = mid - 1;
        }else{
            /* else, mid <= target, won't be ans so escape */
            left = mid + 1;
            /* We update left and right because each round need to cut half to break the loop 
            *  L <= R means L==R also in the loop, we need move any of them to break;
            */
        }
    }

    /*
    * 結論，要用template 1 (while (left <= right) )解這題
    * if (letters[mid] > target) 跟if (letters[mid] <= target) 都可以
    * 但是if (letters[mid] >= target) 跟if (letters[mid] < target) 需要額外處理分支
    * 因為 mid > Target 時 mid有可能是答案，但是 mid == target 不會是答案要丟掉
    */
    return letters[ans];
}
#endif

#if TEMPLATE == 2
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize; /* 這是這題套 template II 特殊解法, 為了wrap‑around 
    找到最右邊 或者超出 都可以用 % 回到0 */
    int mid = 0;
    //int ans = 0; No need! There will be one element left after loop so no record needed
    while( left < right ){
        mid = left + (right - left)/2;
        if(letters[mid] > target){ // it might be the answer so we keep it
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    
    /* here use % to warp back to begin
    *  Happen when the digit is bigger then each one in array
    */
    return letters[left % lettersSize]; 
}
#endif

#if TEMPLATE == 3
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize - 1, mid = 0;

    while( left + 1 < right ){
        mid = left + (right - left)/2;
        if(letters[mid] > target){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    if (letters[left] > target) return letters[left];
    if (letters[right] > target) return letters[right];
    return letters[0]; 
}
#endif

/* Answer from internet
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If we don't find a letter greater than target, wrap around
    return letters[left % lettersSize];
}
*/
