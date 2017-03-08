int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> B;
    vector<bool> t;
    B.reserve(A.size());
    t.reserve(A.size());
    if(A.size()==1)
        return 1;
    for(int i=0;i<A.size();i++)
    {
        B[i] = 0;
        t[i] = 0;
    }
    B[0] = A[0];
    if(A[0] == 0)
        t[0] = 0;
    else
        t[0] = 1;
    for(int i=0;i<A.size()-1;i++)
    {
        if(t[i])
            for(int j=i+1;j<=A[i]+i;j++)
            {
                t[j]=1;
                B[j] = A[j] + j;
                if(B[j] >= A.size()-1)
                    return 1;
            }
    }
    return 0;
}
