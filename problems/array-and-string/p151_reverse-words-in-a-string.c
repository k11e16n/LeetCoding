#define METHOD 1

#if METHOD == 1
void reverse_string(char* s, int start, int end){
    char temp;
    for(int i = start, j = end; i < j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void swap_char( char *s, int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

char* arrange_string_with_space(char *s){
    int string_len = strlen(s), iter = 0, word_start = 0, word_end = 0;

    while( iter <= string_len){
        /* Find a word start point */
        word_start = iter;
        while(s[word_start] == ' '){
            word_start++;
        }

        /* check is ended or not */
        if(s[word_start] == '\0' ){
            char *ret = malloc( iter * sizeof(char) );
            ret[iter-1] = '\0';
            memcpy(ret, s, iter-1);
            return ret;
        }

        /* Not ended yet, finding end of the word */
        word_end = word_start;
        while(s[word_end] != ' ' && s[word_end] != '\0'){
            word_end++;
        }

        /* check is ended or not, but nothing to do */
        /*
        if(s[word_end] == '\0' ){
            printf("word_end hit string end at %d!\nThis means no zero postfix\n", word_end);
        }
        */

        /* Switch the word to iter position */
        for(int i = 0; i < (word_end-word_start); i++){
            swap_char(s, iter+i, word_start+i);
        }

        /* update the iter */
        iter = iter + (word_end-word_start) + 1;
    }

    return s;
}

char* reverseWords(char* s) {
    int count = 0, iter = 0;
    char curr_char = "";
    reverse_string(s, 0, strlen(s) - 1);
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

    return arrange_string_with_space(s);
}

#endif

/* Method from internet */
#if METHOD == 2
void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int i = 0, j = 0;

    // 移除多餘空格並壓縮字符串
    while (j < len) {
        while (j < len && s[j] == ' ') j++;  // 跳過空格
        while (j < len && s[j] != ' ') s[i++] = s[j++];  // 複製非空格字符
        if (j < len) s[i++] = ' ';  // 添加單個空格
    }
    
    // 移除末尾可能的空格
    if (i > 0 && s[i-1] == ' ') i--;
    s[i] = '\0';  // 添加字符串結束符

    // 反轉整個字符串
    reverse(s, 0, i - 1);

    // 反轉每個單詞
    int start = 0;
    for (int end = 0; end <= i; end++) {
        if (end == i || s[end] == ' ') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    return s;
}
#endif
