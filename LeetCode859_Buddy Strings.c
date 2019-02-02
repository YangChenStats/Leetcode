// Put these if you need to run it on your own computer
// #include <stdbool.h>
// #include <stdio.h>

bool buddyStrings(char* A, char* B) {
    size_t nA = strlen(A);
    size_t nB = strlen(B);
    int diff[2]; // Track the difference
    
    // Length zero
    if (nA == 0) return false;
    
    // Different size
    if (nA != nB) return false;
    
    // Same size, compare letters 
    int count = 0;
    for(int i = 0;i < nA;i++){
        if (A[i] != B[i]){
            count++;
            if (count > 2) return false; // More than 2 different letters
            diff[count-1] = i; // Record the difference position
        }
    }
    
    // Zero different letters
    if (count == 0){
        // Size > 26, must have at least two same letters
        if (nA > 26) return true;
        
        // Size <= 26, letter-wise comparsion 
        for (int j = 0;j < nA-1;j++){
            for (int k = j+1;k < nA;k++){
                if (A[j] == A[k]) return true; // Have two same letters
            }
        }
        // Do not have any same letters
        return false;
    }
    
    // One different letters
    if (count == 1) return false;
    
    // Two different letters
    if (A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]) return true;
    return false;
}
