int Solution::numTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> t;
    t.reserve(A+1);
    if(A==0)
        return 0;
    t[0] = 1;
    t[1] = 1;
    t[2] = 2;

    for(int i=3;i<=A;i++)
    {
        t[i] = 0;
        for(int j=1;j<=i;j++)
        {
            t[i] += t[j-1]*t[i-j];
        }
    }
    return t[A];
}
