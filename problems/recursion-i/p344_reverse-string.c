#define METHOD 2

#if METHOD == 1 /* Two pointer */
void swap( char* i, char* j ){
    char temp = *i;
    *i = *j;
    *j = temp;
}

void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    while( i <= j){
        swap( &s[i++], &s[j--]);
    }
}
#endif

#if METHOD == 2 /* recursive */
void reverseString(char* s, int sSize) {
    if( sSize < 2){
        /* We do nothing here */
        return;
    }else{
        // swap first and last
        char temp = s[0];
        s[0] = s[sSize - 1];
        s[sSize - 1] = temp;

        /* sSize - 2 because we finish two char */
        reverseString(s+1, sSize - 2);
    }
}
#endif
