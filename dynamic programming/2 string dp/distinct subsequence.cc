int Solution::numDistinct(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sum=0;
    int len1 = S.length(),len2=T.length();
    /*for(int i=0;i<=len1-len2;i++)
    {
        if(S[i] == T[0])
        {
            if(len2>1 && i<len1-1)
            {
                string S1(S,i+1,len1-i),T1(T,1,len2-1);
                sum += numDistinct(S1,T1);
            }
            else
                sum++;
        }
    }
    return sum;
    */

    vector<vector<int>> t;
    for(int i=0;i<len2+1;i++)
    {   vector<int> v;
        for(int j=0;j<len1+1;j++)
            v.push_back(0);
        t.push_back(v);
    }
    for(int i=1;i<=len2;i++)
    {
        for(int j=1;j<=len1;j++)
        {
            if(S[j-1]==T[i-1])
                t[i][j]=t[i-1][j-1]+t[i][j-1]+1;
            else
                t[i][j]=t[i][j-1];
        }
    }
    return t[len2][len1];


	//for (int i = 0; i < S.length(); i++)
	//	table[i][0] = 1;
 /*
	for (int i = 1; i <= S.length(); i++) {
		for (int j = 1; j <= T.length(); j++) {
			if (S[i - 1] == T[j - 1]) {
				table[i][j] += table[i - 1][j] + table[i - 1][j - 1];
			} else {
				table[i][j] += table[i - 1][j];
			}
		}
	}

	return table[S.length()][T.length()];
*/
}
