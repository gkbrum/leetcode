char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int freqPlate[ 26 ] = { 0 };    //contador de freq de letra
    int solutionLen = 16;   //words[i] tem no maximo tamanho 15
    char *solution;

    for( int i = 0; licensePlate[ i ] != '\0'; i++ ){   //conta quantas letras de cada tipo tem em plate
        if( isalpha( licensePlate[ i ] ) != 0 ){
            freqPlate[ tolower( licensePlate[ i ] ) - 'a' ]++;
        }
    }

    for( int i = 0; i < wordsSize; i++ ){   //percorre words
        int freqWord[ 26 ] = { 0 };
        int len = strlen( words[ i ] );

        
        for( int j = 0; j < len; j++ ){     //conta letras em words[i]
            freqWord[ tolower( words[ i ][ j ] ) - 'a' ]++;
        }        
    
        bool valid = true;

        for( int j = 0; j < 26; j++ ){      //verifica se as letras em word satisfazem plate
            if( freqPlate[ j ] > freqWord[ j ] ){
                valid = false;
            }
        }

        if( valid ){
            if( len < solutionLen ){    //verifica se a solução encontrada é a menor
                solution = words[ i ];
                solutionLen = strlen( words[ i ] );
            }
        }
    }
    return solution;
}