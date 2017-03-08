/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Integer
 */
 int min(int a,int b){return (a<b?a:b);}

int minPathSum(int** A, int n11, int n12) {
    int B[1000][1000];
    int i=0,j=0;
    B[0][0] = A[0][0];
    for(i=1;i<n11;i++)
        B[i][0] = A[i][0] + B[i-1][0];
    for(j=1;j<n12;j++)
        B[0][j] = A[0][j] + B[0][j-1];
    i=j=0;
    for(i=1;i<n11;i++)
    {
        for(j=1;j<n12;j++)
        {
            B[i][j] = A[i][j] + min(B[i-1][j],B[i][j-1]);
        }
    }
    return B[n11-1][n12-1];
}
