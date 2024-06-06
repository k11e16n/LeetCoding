bool canConstruct(char* ransomNote, char* magazine) {
        int i=0, j=0, sum=0;
        int ransomNoteLen=strlen(ransomNote);
        int magazineLen=strlen(magazine);
        char *dupRansomNote = strdup(ransomNote);
        char *dupMagazine= strdup(magazine);

        if(ransomNoteLen > magazineLen){
                free(dupRansomNote);
                free(dupMagazine);
                return false;
        }

        for(j=0; j<magazineLen; j++){
                for(i=0; i<ransomNoteLen; i++){
                        if ( dupRansomNote[i] != '\0' && dupRansomNote[i] == dupMagazine[j] ){
                                dupRansomNote[i] = '\0';
                                sum++;
                                break;
                        }
                }
                if(sum==ransomNoteLen){
                        free(dupRansomNote);
                        free(dupMagazine);
                        return true;
                }
        }
        free(dupRansomNote);
        free(dupMagazine);
        return false;
}
