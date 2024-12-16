/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

*/



/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced assume caller calls free().
*/
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);

    int **x = malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        x[i] = malloc(sizeof(int) * (i + 1));
        x[i][0] = 1;
        x[i][i] = 1;

        }
                                                                            
    for (int i = 2; i < numRows; i++) {
        for (int j = 1; j < i; j++) {
            x[i][j] = x[i - 1][j - 1] + x[i - 1][j];

        }

        }
    return x;
    
} 
