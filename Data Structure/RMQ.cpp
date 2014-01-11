const int MX = 1e5 + 7 ;
const int MXLG = 17;
int dp[MX][MXLG];
int a[MX] , N ;
int preprocess() {
    for( int i = 0 ; i < N ; i++ ) dp[i][0] = a[i]; // init the 0th level s = 1 , k = 0
    for( int s = 2 , k = 1 ; s <= N ; k++ ) { // powering up each level with s *= 2 , and k ++
        for( int i = 0 ; i + s <= N ; i++ )
            dp[i][k] = min( dp[i][k-1] , dp[i+s/2][k-1] );
        s *= 2 ;
    }
}
int rmq(int i , int j ) {
    int range = j - i + 1 , s = 1, k = 0 ;
    for( s = 1 , k = 0 ; s * 2 <= range ; k++ , s *= 2 );
    int ans = min( dp[i][k] , dp[i+range-s][k]);
    return ans;
}
