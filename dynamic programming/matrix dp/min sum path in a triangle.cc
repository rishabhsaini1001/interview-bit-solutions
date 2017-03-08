/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * Each row in the 2D array starts with the size of the row. A[i][0] represents the number of elements in row i.
 *
 * @Output Integer
 */
int max(int a,int b)
{
    return a<b?a:b;
}
int minimumTotal(int** A, int n11) {
    if(n11 == 0)
        return 0;
    if(n11 == 1)
        return A[0][1];
    int t[n11];
    int i=0;
    for(i=0;i<n11;i++)
        t[i] = A[n11-1][i+1];
    for( i=n11-2;i>=0;i--)
    {
        int j;
        for(j=0;j<=i;j++)
        {
            t[j] = max(t[j],t[j+1]);
            t[j] += A[i][j+1];
        }
    }
    return t[0];
}
