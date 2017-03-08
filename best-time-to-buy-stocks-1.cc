int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()<=1)
        return 0;
    int profit = 0,min = A[0];
    for(int i=1;i<A.size();i++)
    {
        if(min>A[i])
            min = A[i];
        else if(profit<A[i]-min)
            profit=A[i]-min;
    }
    return profit;
}
