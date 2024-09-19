int strStr(char* haystack, char* needle) {
    int result = -1;
    int haystack_index = 0, haystack_len = strlen(haystack);
    int needle_index = 0, needle_len = strlen(needle);

    while( haystack_index <= (haystack_len - needle_len) ){
        while( haystack[haystack_index+needle_index] == needle[needle_index]){
            if( needle_index == needle_len - 1 ){
                return haystack_index;
            }
            needle_index++;
        }

        haystack_index++;
        needle_index = 0;
    }
    return result;
}
