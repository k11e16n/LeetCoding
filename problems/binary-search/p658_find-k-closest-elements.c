/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int left = 0, right = arrSize - k, mid = 0;
    /* right using n-k because the biggest subset is k elements */

    while( left < right ){
        mid = (left + right)/2;
        /* lets say x-arr[mid] is A
        *  lets say arr[mid+k] - x is B
        *  A > B: 這個窗口起得太「左」了──左邊那端離 x 太遠
        *  A <= B: 這個窗口起得太「右」了（或剛好）──我們可以把右邊界收縮到 mid
        *  Remember, mid is the start point of the sub string. if arr[mid]
        *  is too far to left then the right side of mid is more farther so it can be move!
        */
        if( x - arr[mid] > arr[mid+k] - x){
            left = mid + 1;
        }else{
            right = mid;
        }
    }

    *returnSize = k;
    return arr + left;
}
