int kthGrammar(int n, int k) {
    
    /* Base casse */
    if( n == 1 ){
        return 0;
    }

    /* get previous number */
    int prev_k_mod = k % 2;
    int prev_k = k / 2 + prev_k_mod;
    if(kthGrammar(n-1, prev_k) == 0){
        // case 0 1
        return !prev_k_mod;
    }else{
        // case 1 0
        return prev_k_mod;
    }
}
