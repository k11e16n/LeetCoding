#define METHOD 2

#if METHOD == 1
char* addBinary(char* a, char* b) {

    int carry = 0;
    int iter_a = strlen(a) - 1, iter_b = strlen(b) - 1;
    int ret_size = (strlen(a)>=strlen(b))?strlen(a):strlen(b);

    char *ret_char = malloc( (ret_size + 1) * sizeof(char) );
    ret_char[ret_size--] = '\0';

    while( iter_a >= 0 || iter_b >= 0 ){
        /* consider '0' = 48 */
        int sum = (iter_a >= 0)?a[iter_a--]:0;
        sum += (iter_b >= 0)?b[iter_b--]:0;
        /* 96 = 0 no carry
         * 97 = 1 no carry
         * 98 = 0 with carry
        */
        if(sum == 96 ){
            ret_char[ret_size--] = (carry)?'1':'0';
            carry = 0;
        }else if(sum == 97 ){
            if(carry){
                ret_char[ret_size--] = '0';
                carry = 1;
            }else{
                ret_char[ret_size--] = '1';
                carry = 0;
            }
        }else if(sum == 98 ){
            ret_char[ret_size--] = (carry)?'1':'0';
            carry = 1;
        }else{ //only one number
            if( sum == 48 ){
                ret_char[ret_size--] = (carry)?'1':'0';
                carry = 0;
            }else if(sum == 49){
                if(carry){
                    ret_char[ret_size--] = '0';
                    carry = 1;
                }else{
                    ret_char[ret_size--] = '1';
                    carry = 0;
                }
            }
        }
    }

    /* make it as a string */
    if(carry){
        char *new_ret_char = malloc((strlen(ret_char)+2) * sizeof(char));
        memcpy(new_ret_char+1, ret_char, strlen(ret_char) * sizeof(char));
        new_ret_char[0] = '1';
        new_ret_char[strlen(ret_char)+1] = '\0';
        free(ret_char);
        return new_ret_char;
    }

    return ret_char;
}

#endif

#if METHOD == 2
char* addBinary(char* a, char* b) {

    int carry = 0, sum = 0, len_a = strlen(a), len_b = strlen(b);
    int ret_len = (len_a>=len_b)?len_a:len_b;
    char *ret_char = malloc( (ret_len + 1) * sizeof(char) );

    ret_char[ret_len--] = '\0';

    while( ret_len >= 0){
        /* 1. consider '0' = 48 
         * 2. if sum > 2, div will not be 0, use it for get carry
         * 3. we could use mod 2 to get the number
        */

        sum = carry;

        if( len_a-- > 0){
            sum += a[len_a] - '0';
        }

        if( len_b-- > 0){
            sum += b[len_b] - '0';
        }

        ret_char[ret_len--] = (sum % 2)==1?'1':'0';
        carry = sum / 2;
    }

    /* make it as a string */
    if(carry){
        char *new_ret_char = malloc((strlen(ret_char)+2) * sizeof(char));
        memcpy(new_ret_char+1, ret_char, strlen(ret_char) * sizeof(char));
        new_ret_char[0] = '1';
        new_ret_char[strlen(ret_char)+1] = '\0';
        free(ret_char);
        return new_ret_char;
    }

    return ret_char;
}
#endif
