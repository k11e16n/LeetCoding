bool canConstruct(char* ransomNote, char* magazine) {
    int map[26] = {0};
    
    while( *magazine != '\0' ){
        map[*magazine-'a']++;
        magazine++;
    }
    while( *ransomNote != '\0' ){
        map[*ransomNote-'a']--;
        if(map[*ransomNote-'a']<0) return false;
        ransomNote++;
    }
    return true;
}
