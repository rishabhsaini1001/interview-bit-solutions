struct data{
    int d1;
    int d2;
};

int Solution::anytwo(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<string,data> t;
    for(int i=0;i<A.size()-1;i++)
    {
        string s1(A,i,1);
        for(int j=i+1;j<A.size();j++)
        {
            string s2(A,j,1);
            string s = s1+s2;
            data d = {i,j};
            //auto f = t.insert({s,i});

            unordered_map<string,data>::const_iterator got = t.find (s);
              if ( got != t.end() && got->second.d1!=i && got->second.d2!=j)
                return 1;
              else if(got == t.end())
                {

                    t.insert({s,d});
                }


            /*if (!f.second )//&& f.second!=i)
            //{
            //    return f.second;
            }*/
        }
    }
    return 0;
}
