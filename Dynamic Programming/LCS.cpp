#define SZ 1007

int dp[SZ][SZ] , N , M ;
string a , b , lcs[SZ][SZ];

int solve(){
    N = a.size() , M = b.size() ;
    for(int i = 1 ; i <= N ; i++ )
        for(int j = 1 ; j <= M ; j++ ){
            if( a[i-1] == b[j-1] ) {
                dp[i][j] = dp[i-1][j-1] + 1 ;
                lcs[i][j] = lcs[i-1][j-1] + a[i-1];
            }
            else if( dp[i][j-1] > dp[i-1][j] ) {
                dp[i][j] = dp[i][j-1];
                lcs[i][j] = lcs[i][j-1];
            }
            else if( dp[i][j-1] < dp[i-1][j] ) {
                dp[i][j] = dp[i-1][j];
                lcs[i][j] = lcs[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j-1];
                lcs[i][j] = min( lcs[i-1][j] , lcs[i][j-1] );
            }
        }
        return dp[N][M];
}
