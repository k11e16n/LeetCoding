char* longestCommonPrefix(char** strs, int strsSize) {
    int strs_index = 0, sub_strs_index = 0;
    char *ret_char = NULL, compare_char = "";

    if(strs == NULL || strsSize <= 1){
        return strs[0];
    }

    /* set first char as default comparison */
    compare_char = strs[strs_index][sub_strs_index];

    while(strs_index < strsSize && sub_strs_index < strlen(strs[strs_index]) ){

        /* If match we move to next string */
        if (strs[strs_index][sub_strs_index] == compare_char){
            strs_index++;
        }else{
            /* Not Match so quit */
            break;
        }

        if(strs_index == strsSize){
            /* If each strings char is same, we check next char for each strings */
            strs_index = 0;
            sub_strs_index++;
            compare_char = strs[strs_index][sub_strs_index];
        }
        
    }

    /* construct the return string */
    ret_char = malloc( (sub_strs_index + 1) * sizeof(char));
    memcpy(ret_char, strs[0], sub_strs_index * sizeof(char) );
    ret_char[sub_strs_index] = '\0';

    return ret_char;
}

/* Idea from internet */
/* idea: take the first string in strs no matter the length! */
char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(sizeof(char) * (strlen(strs[0]) + 1));
    int i = -1;

    do{
        i++;
        prefix[i] = strs[0][i];
        for(int j=0; j < strsSize; j++){
            if(!strs[j][i] || prefix[i] != strs[j][i])
                prefix[i] = '\0';
        }
    } while(prefix[i]);
    return prefix;
}
