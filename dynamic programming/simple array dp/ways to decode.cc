int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //vector<int> r;
    //r.reserve(A.length());
    int r[1000000];
    for(int i=0;i<A.length();i++)
        r[i] = 0;
    r[A.length()]=r[A.length()-1]=1;
    if(A=="0")
        return 0;
        if(A=="1")
        return 1;
        if(A[0]=='0')
        return 0;
    for(int i=A.length()-1;i>=0;i--)
    {


            r[i] = r[i+1];
            if(A[i+2]!='0'&&A[i]!='0' && A[i+1]!='0' && (A[i]=='1' || (A[i]=='2'&&(A[i+1]=='1'||A[i+1]=='0'||A[i+1]=='2'||A[i+1]=='3'||A[i+1]=='4'||A[i+1]=='5'||A[i+1]=='6'))))
            r[i] += r[i+2];

            if((A[i]=='0'||A[i]=='3'||A[i]=='4'||A[i]=='5'||A[i]=='6'||A[i]=='7'||A[i]=='8'||A[i]=='9') && A[i+1]=='0')
            {
                r[0]=0;
                break;
            }


    }
    return r[0];
}
