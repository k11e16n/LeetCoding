void reverse_string(char* s, int start, int end){
    char temp;
    for(int i = start, j = end; i < j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char* reverseWords(char* s) {
    int count = 0, iter = 0;
    char curr_char = "";

    while( iter <= strlen(s) ){
        if( s[iter] == ' ' || s[iter] == '\0'){
            reverse_string(s, iter-count, iter-1);
            count = 0;
            iter++;
            continue;
        }
        count++;
        iter++;
    }
    
    return s;
}
