vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool carry = 1;
    int n = A.size();
    int k=n-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=0)
        {
            k=i;
            break;
        }
    }
    int i=n-1;
    while(carry && i>=k)
    {
        A[i]++;
        if(A[i]>9)
            A[i]=0;
        else
            carry=0;
        i--;
    }
    if(!carry)
    {
        for(int j=k;j<n;j++)
            A[j-k] = A[j];
        A.resize(n-k);
        return A;
    }
    if(i>=0)
    {
        A[i] = 1;
        for(int j=i;j<n;j++)
            A[j-i] = A[j];
        A.resize(n-i);
        return A;
    }
    if(i<0)
    {
        A.push_back(0);
        for(int i=n;i>0;i--)
            A[i] = A[i-1];
        A[0] = 1;
        return A;
    }
}
