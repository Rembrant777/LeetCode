// https://leetcode.com/problems/toeplitz-matrix/

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    bool ans = true; 

    for (int i = 0; i < matrixSize -1; i++) {
        for (int j = 0; j < matrixColSize[i] -1; j++) {
            if (matrix[i][j] != matrix[i+1][j+1]) {
                ans = false; 
                return ans; 
            }
        }
    }

    return ans; 
}