const int MX = 1e5 + 7 ;
const int MXLG = 17;
int dp[MX][MXLG];
int a[MX] , N ;
int preprocess() {
    for( int i = 0 ; i < N ; i++ ) dp[i][0] = i ;
    for( int j = 1 ; ( 1 << j ) <= N ; j++ ){
        for( int i = 0 ; i + ( 1 << j ) - 1 < N ; i++ )
            if( a[ dp[i][j - 1] ] < a[ dp[ i + ( 1 << ( j - 1 ) )][j - 1] ])
                 dp[i][j] = dp[i][ j - 1];
            else dp[i][j] = dp[ i + ( 1 << ( j - 1 ) )][j - 1];
    }
}
int rmq(int i , int j ) {
    int k = ( int )log2( j - i + 1 );
    if( a[ dp[i][k] ] <= a[ dp[ j - (1 << k) + 1 ][k] ] )
        return a[ dp[i][k] ];
    else
        return a[ dp[ j - (1 << k) + 1 ][k] ];
}
