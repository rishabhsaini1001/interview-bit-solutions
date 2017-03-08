int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> t;
    vector<int> l;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        t.push_back(1);
        l.push_back(1);
    }
    for(int i=0,j=n-1;i<n,j>=0;i++,j--)
    {
        for(int k=0,z=n-1;k<i,z>j;k++,z--)
        {
            int max=0;
            if(A[k]<A[i] && t[k]>max)
                max = t[k]+1;
            if(max>t[i])
                t[i]=max;
            max=0;
            if(A[z]<A[j] && l[z]>max)
                max = l[z] + 1;
            if(max>l[j])
                l[j]=max;
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
        if(t[i]+l[i]-1>max)
            max = t[i]+l[i]-1;
    return max;
}
