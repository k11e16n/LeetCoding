#define METHOD 3

#if METHOD == 1 // My Original answer
double myPow(double x, int n) {
    /* Coner cases */
    if(n==0 || x==1){
        return 1;
    }else if( n == 2147483647 || n == -2147483647){
        if(x < 0){
            return x;
        }
        return 0;
    }else if(n < 0){
        double result = 1 / x * myPow(x, n+1);
        return result;
    }else{
        double result = x * myPow(x, n-1);
        return result;
    }
}
#endif

#if METHOD == 2 // Better recursion
double myPow(double x, int n) {
    double temp;
    if (n == 0)
        return 1;
    temp = myPow(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else {
        if (n > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}
/* The previous is same as
double myPow(double x, int n) {
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}
*/
#endif

#if METHOD == 3
double myPow(double x, int n) {
    double result = 1.0;
    // The reason using long is for case x=1.00000 n = -2147483648
    // because -n will overflow in INT
    // INT is -2147483648 ~ 2147483647
    // Thus using long to handle it
    long long exponent = n;

    // If n is negative, invert x and use the positive exponent
    if (n < 0) {
        x = 1.0 / x;
        exponent = -exponent;
    }

    while (exponent > 0) {
        // If exponent is odd, multiply the current result by x
        if (exponent % 2 == 1) {
            result *= x;
        }
        // Square x and halve the exponent
        x *= x;
        exponent /= 2;
    }

    return result;
}
#endif
