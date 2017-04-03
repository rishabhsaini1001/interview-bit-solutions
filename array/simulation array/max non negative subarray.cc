vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int sum=0,maxSum=0,s=-1,f=-1,S=0,F=-1,pos=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {
            pos++;
            sum+=A[i];
            if(s==-1)
                s=i;
            if(i==A.size()-1 || A[i+1]<0)
            {
                f=i;
                if(sum>maxSum || (sum==maxSum && f-s>F-S))
                    {
                        maxSum = sum;
                        S=s;
                        F=f;
                    }
                sum = 0;
                s=-1;
                f=-1;
            }
        }
    }
    vector<int> r;
    if(F!=-1)
        for(int i=0;i<=F-S;i++)
            r.push_back(A[i+S]);
    //r.push_back(pos);
    //r.push_back(F);
    return r;
}
