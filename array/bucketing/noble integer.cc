int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        if(i<A.size()-1 && A[i] != A[i+1])
        {
            if(A[i] == A.size() - i -1)
                return 1;
        }
    }
    if(A[A.size()-1] == 0)
        return 1;
    return -1;
}
