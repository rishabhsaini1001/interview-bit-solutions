/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int jump(int* A, int n1) {
    if(n1<=1) return 0;
	int dp[n1];
	dp[0] = 0;
	int i=0,j=0,next=0,n=n1;
	for( i=0, next=1; i<n && next<n ;i++){
		if(i==next-1 && A[i]==0)
			return -1;
		for( j=next; j<n && j <= i + A[i]; j++, next++){
			dp[j] = 1 + dp[i];
		}
	}

	return dp[n-1];


}
