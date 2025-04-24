int mySqrt(int x) {
    /* exception condition */
    if(x < 2)
        return x;

    long left = 0, right = x, half = 0, sqrt = 0, ans = 0;

    while( left <= right ){ 
        /* Find the half and check */
        half = (left + right)/2;
        sqrt=half*half;

        if ( sqrt == x ){ // get answer
            return half;
        }else if( sqrt < x){ // smaller
            /* We need to check greater part, but it might be answer so we keep it */
            ans = half;
            left = half + 1;
        }else{ //greater
            right = half - 1;
        }
    }

    return ans;
}
