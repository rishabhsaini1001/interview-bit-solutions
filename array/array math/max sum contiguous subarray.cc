int max(int a,int b)
{
    return a>b?a:b;
}

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int sum = A[0], maxSum=A[0];
    for(int i=1;i<A.size();i++)
    {
        //if(A[i]>=0)
        {
            sum = max(0,sum);
            sum += A[i];
            maxSum = max(sum,maxSum);
        }

    }
    return (int)maxSum;
}
