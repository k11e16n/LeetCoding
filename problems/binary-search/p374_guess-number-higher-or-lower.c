/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
extern int guess(int num);

int guessNumber(int n){
    int left = 1, right = n, mid = 0, guess_result = 0;

	while(left <= right ){
        mid = left + (right - left)/2;
        guess_result = guess(mid);

        if ( guess_result == 0){
            return mid;
        }else if( guess_result == -1){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}
