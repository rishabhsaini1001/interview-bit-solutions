bool present(string A,vector<string> B)
{
    for(int i=0;i<B.size();i++)
        if(A == B[i])
            return 1;
    return 0;
}

bool w(string s, vector<string> B) {
        if(B.size()==0) return false;

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(present(word,B))
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }

bool word(string s, unordered_set<string> dict) {
        if(dict.size()==0) return false;

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }

int Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*vector<vector<bool>> t;
    int n = A.length();
    for(int i=0;i<n;i++)
        {
            vector<bool> temp;
            for(int j=0;j<n;j++)
                {
                    int moretemp = 0;
                    temp.push_back(moretemp);
                }
            t.push_back(temp);
        }
    for(int i=0;i<n;i++)
    {
        string s(A,i,1);
        if(present(s,B))
            t[i][i] = 1;
    }
    for(int j = 1;j<n;j++)
    {
        for(int k=0;k+j<n;k++)
        {
            string s(A,k,j+1);
            if(present(s,B))
                t[k][k+j]=1;
            for(int z=k;z<k+j-1;z++)
            {
                if(t[k][z] && t[z+1][k+j])
                    t[k][k+j]=1;
            }
        }
    }
    return t[0][n-1];*/
    unordered_set<string> ty;
    for(int i=0;i<B.size();i++)
        ty.insert(B[i]);
    return word(A,ty);
}
