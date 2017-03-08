int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_set<int> t;
    for(int i=A.size()-1;i>=0;i--)
    {
        t.insert(A[i]);
        A.resize(i);
    }
    int i = 1;
    while(1)
    {
    unordered_set<int>::const_iterator got = t.find (i);
      if ( got == t.end() )
        return i;
      else
        i++;
    }
}
