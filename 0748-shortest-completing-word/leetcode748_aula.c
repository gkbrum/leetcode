bool verifyIndex( int current, int *usedIndex );

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    char letters[6];
    int usedIndex[6];
    int j = 0, f;

    for( int i = 0; i < 7; i++ ){
        if( isalpha( licensePlate[i] ) != 0 ){
            letters[j] = tolower( licensePlate[i] );
            j++;
        } else if (  licensePlate[i] == '\0' ){
            letters[j] == '\0';
        }
    }
    
    int i;

    for( i = 0; i < wordsSize; i++ ){

        f = 0;
        for( int i = 0; i < 6; i++ ){
            usedIndex[i] = -1;
        }
        
        for( int j = 0; letters[f] != '\0'; j++ ){
            if( words[i][j] == letters[f] && verifyIndex( j, usedIndex ) ){
                f++;
                usedIndex[f] == j;
            }
        }
    }

    return words[i];

}

bool verifyIndex( int current, int *usedIndex ){
    for( int i = 0; i < 6; i++){
        if( current == usedIndex[i] ){
            return false;
        }
    }
    return true;
}