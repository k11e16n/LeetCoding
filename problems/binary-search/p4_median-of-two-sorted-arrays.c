bool isOdd(int num){
    return num & 1;
}

double findMedianSortedArrays(int* A, int m, int* B, int n) {
    /* use small array as to do the BS */
    if( m > n){
        return findMedianSortedArrays( B, n, A, m);
    }

    /* Find a cut so that every elemnts in left <= right side
     *  i: cut position in array A
     *  j: cut position in array B
     */
    int iLeft = 0, iRight = m; // i is not number is cut position, so we use m, not m-1
    while( iLeft <= iRight ){
        int i = (iLeft + iRight) / 2;
        /* j = (m+n+1)/2 - i: position j is determine by i
         * +1 is because whether odd and even div 2 has same result
         * look closer, 0<=i<=m && m <=n
         * these two conditions can ensure j is legal using the following formula.
         * How you get this formula?
         * A: We're finding two cut position make left side <= right side
         * i+j(number of left side) = (m+n+1)/2 (half of total number)
         */
        int j = ( m + n + 1) / 2 - i;

        /* obviously, A[i-1] < A[i] && B[j-1] < B[j], so we check only the other two conditions.
         *  while 0 < i < m, then j is always legal.
         */
        if( i<m && B[j-1] > A[i] ){ // i too small should move right 
            iLeft = i + 1;
        }else if( i>0 && A[i-1] > B[j]){ // i too big should move left
            iRight = i - 1;
        }else{
            /* cut position found, check ans */
            int maxLeft = 0;
            if(i == 0) maxLeft = B[j-1];
            else if(j == 0) maxLeft = A[i-1];
            else maxLeft = (A[i-1] > B[j-1])?A[i-1]:B[j-1];

            /* Checking odd or even */
            if( isOdd(m+n) ) return maxLeft;

            /* if even we need to get mean number */
            int minRight = 0;
            if(i == m) minRight = B[j];
            else if(j == n) minRight = A[i];
            else minRight = (A[i]<B[j])?A[i]:B[j];

            return (maxLeft + minRight)/2.0;
        }
    }
    return 0.0;
}

