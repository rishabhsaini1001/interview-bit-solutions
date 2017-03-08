/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Integer
 */
int uniquePathsWithObstacles(int** A, int n11, int n12) {
    int i=0,j=0;
    int B[100][100];
    if(A[0][0] == 0)
        B[0][0] = 1;
    else
        B[0][0] = 0;
    for(i=1;i<n11;i++)
        if(A[i][0] == 0)
            B[i][0] = B[i-1][0];
        else
            B[i][0] = 0;
    for(j=1;j<n12;j++)
        if(A[0][j] == 0)
            B[0][j] = B[0][j-1];
        else
            B[0][j] = 0;
    i=j=1;
    for(;i<n11;i++)
    {
        for(j=1;j<n12;j++)
        {
            if(A[i][j] == 0)
                B[i][j] = B[i-1][j] + B[i][j-1];
            else
                B[i][j] = 0;
        }
    }
    return B[n11-1][n12-1];
}
