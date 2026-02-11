/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: The returned array and *returnColumnSizes array must be malloced, 
 * assume caller calls free().
 */

int** transpose(int** matrix, int matrixSize, int* matrixColSize, 
                int* returnSize, int** returnColumnSizes) {
    
    int m = matrixSize;          // number of rows
    int n = matrixColSize[0];    // number of columns
    
    // Transposed matrix will have dimensions n x m
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    int** result = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    
    // Fill transposed matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}