int max(int a,int b)
{
    return a>b?a:b;
}

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*int profit = 0;
    int min = INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] < min)
            min = A[i];
        else
            {
                profit += A[i] - min;
                min = INT_MAX;
            }
    }
    return profit;*//*
    int t[1000][1000];
    for(int i=0;i<A.size();i++)
        t[i][i] = 0;
    //return t[0][A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        for(int j = i+1;j<A.size();j++)//  int j=A.size()-1;j>i;j--)
        {
            int min = 0;
            if(A[j] - A[i] > 0)
                min = A[j] - A[i];
            if(t[i][j-1] > min)
                min = t[i][j-1];
            if(t[i+1][j] > min)
                min = t[i+1][j];
            t[i][j] = min;
        }
    }
    *//*
    int t[1000][1000];
    for(int i=0;i<A.size();i++)
        t[i][i] = 0;
    //return t[0][A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        for(int j = i+1;j<A.size();j++)
        {
            t[i][j] = max(A[j] - A[i],0);
            for(int k = i+1;k<j;k++)
            {

                int m1 = max(t[i][k] + t[k+1][j], t[i][k-1] + t[k][j]);
                t[i][j] = max(m1,t[i][j]);


            }
        }
    }*/
     int ret = 0;
        for(int i=1; i<A.size(); i++) {
            ret += A[i]>A[i-1] ? A[i]-A[i-1] : 0;
        }
        return ret;


    //return t[0][A.size()-1];
}
