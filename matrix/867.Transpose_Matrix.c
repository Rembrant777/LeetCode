// https://leetcode.com/problems/transpose-matrix/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int** ret_matrix; 

    // allocate space for matrix and array
    int M = matrixSize; 
    int N = (*matrixColSize); 

    *returnSize = N; 
    *returnColumnSizes = (int *) malloc(N * sizeof(int*)); 
    ret_matrix = (int **) malloc(N * sizeof(int*)); 
    
    for (int i = 0; i < N; i++) {
        ret_matrix[i] = (int *) malloc(M * sizeof(int)); 
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ret_matrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        (*returnColumnSizes)[i] = M; 
    }

    return ret_matrix; 
}