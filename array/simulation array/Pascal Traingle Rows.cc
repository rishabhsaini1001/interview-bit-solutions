vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > result;
    vector<int> firstRow,secondRow;
    if(A==0)
        return result;
    firstRow.push_back(1);
    secondRow.push_back(1);
    secondRow.push_back(1);
    result.push_back(firstRow);
    if(A == 1)
        return result;
    result.push_back(secondRow);
    if(A == 2)
        return result;
    for(int i=2;i<A;i++)
    {
        vector<int> row;
        row.push_back(1);
        for(int k=1;k<=i-1;k++)
        {
            int temp = result[i-1][k-1] + result[i-1][k];
            row.push_back(temp);
        }
        row.push_back(1);
        result.push_back(row);
    }
    return result;
}
