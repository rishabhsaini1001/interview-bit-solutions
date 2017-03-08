int Solution::lis(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> f;

    f.reserve(A.size());
    f[0] = 1;
    int M = 1,m=f[0];
    for(int i=1;i<A.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && f[j]>=m)
                m = f[j]+1;
        }
        f[i] = m;
        if(M<f[i])
            M=f[i];
        m=f[0];
    }
    return M;
}
