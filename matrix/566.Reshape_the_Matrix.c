// https://leetcode.com/problems/reshape-the-matrix/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int originalElements = matSize * (*matColSize); 
    if (originalElements != r * c) {
        // size not match, just return original matrix and set values from 
        // matSize to returnSize
        // matColSize to returnColumnSizes

        *returnSize = matSize; 
        *returnColumnSizes = (int *) malloc(matSize * sizeof(int));

        for (int i = 0; i < matSize; i++) {
            (*returnColumnSizes)[i] = matColSize[i]; 
        }
        
        return mat; 
    }

    int **ret_mat = (int **) malloc(r * sizeof(int*)); 
    *returnSize = r; 
    *returnColumnSizes = (int *) malloc(r * sizeof(int)); 

    for (int i = 0; i < r; i++) {
        ret_mat[i] = (int *) malloc(c * sizeof(int)); 
        (*returnColumnSizes)[i] = c; 
    }


    for (int i = 0; i < r * c; i++) {
        ret_mat[i / c][i % c] = mat[i / (*matColSize)][i % (*matColSize)]; 
    }

    return ret_mat; 
}