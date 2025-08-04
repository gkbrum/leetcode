//no fim da aula estava retornando 16 em todos os testcases
#define MOD 1000000007

long long modPow(long long base, long long exp){
    long long result = 1;
    base = base % MOD;

    while( exp > 0 ){
        if(exp % 2 == 1){
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;

        exp = exp / 2;
    }

    return result;
}

long long modInverse(long long a){
    return modPow(a, MOD - 2);
}

long long fat(int n){
    if(n == 0 || n == 1) return 1;

    return (n * fat(n - 1)) % MOD;
}

long long dfs(int *nums, int numsSize){
    if ( numsSize < 3 ) return 1;
    
    int rootVal = nums[0], leftSize = 0, rightSize = 0;
    int *left = malloc(sizeof(int) * numsSize);
    int *right = malloc(sizeof(int) * numsSize);

    for(int i = 1; i < numsSize; i++){
        if(nums[i] > rootVal){
            right[rightSize] = nums[i];
            rightSize++;
        }else{
            left[leftSize] = nums[i];
            leftSize++;
        }
    }

    long long P = ( fat(numsSize - 1) ); 
    P = (P * modInverse( fat(leftSize) )) % MOD;
    P = (P * modInverse( fat(rightSize) )) % MOD;

    long long leftWays = dfs(left, leftSize);
    long long rightWays = dfs(right, rightSize);

    long long result = (((P * leftWays) % MOD) * rightWays) % MOD;

    free(left);
    free(right);

    return result;
}

int numOfWays(int* nums, int numsSize) {
    return ( dfs(nums, numsSize) - 1 + MOD ) % MOD;
}