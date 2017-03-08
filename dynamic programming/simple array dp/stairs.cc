int Solution::climbStairs(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a=0,b=1,c=2;
    if(A==0)
    return 0;
    if(A==1)
    return 1;
    if(A==2)
    return 2;

    for(int i=3;i<=A;i++)
    {
        int t = c;
        c = b+c;
        b = t;
    }
    return c;
}
