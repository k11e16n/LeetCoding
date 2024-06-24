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
