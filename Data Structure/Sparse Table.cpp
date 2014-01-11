/** 1-D Range Queries **/

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

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** 2-D Square Queries **/

//  top left corner is (I, J) and whose bottom right corner is (I+S-1, J+S-1)

const int MX = 507 ;
const int MXLG = 9 ;
int dp[MX][MX][MXLG];
int a[MX][MX] , N ;
int preprocess() {
    for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < N ; j++ )  dp[i][j][0] = a[i][j];
    for( int s = 2 , k = 1 ; s <= N ; k++ ){
        for( int i = 0 ; i + s <= N ; i++ )
            for( int j = 0 ; j + s <= N ; j++ ){
                int mx = dp[i][j][k-1];
                mx = max( mx , dp[i+s/2][j][k-1]);
                mx = max( mx , dp[i][j+s/2][k-1]);
                mx = max( mx , dp[i+s/2][j+s/2][k-1]);
                dp[i][j][k] = mx ;
            }
        s *= 2 ;
    }
}
int rmq(int i , int j , int range ){
    int s = 1 , k = 0 ;
    for( s = 1 , k = 0 ; s * 2 <= range ; s *= 2 , k++ );
    int ans = dp[i][j][k];
    ans = max( ans , dp[i+range-s][j][k] );
    ans = max( ans , dp[i][j+range-s][k] );
    ans = max( ans , dp[i+range-s][j+range-s][k]);
    return ans;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Rectangle Queries **/

const int MX = 256 ;
int LogTable[MX];
int dp[9][9][MX][MX];
int N , a[MX][MX] ;

void preprocess()
{
    for( int i = 2 ; i < MX; i++ ) LogTable[i] = LogTable[i>>1]+1;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            dp[0][0][i][j] = a[i][j];
    for(int i = 0 ; i <= LogTable[N] ;i++)
        for(int j = 0 ; j <= LogTable[N] ;++j ){
            if(i == 0 && j == 0 ) continue;
            for(int x = 0 ; x + (1<<j) <= N ; x++)
                for(int y = 0 ; y + (1<<i) <= N ; y++)
                    if( i == 0 )
                        dp[i][j][x][y]= max(dp[i][j-1][x][y],dp[i][j-1][x+(1<<(j-1))][y]);
                    else
                        dp[i][j][x][y]= max(dp[i-1][j][x][y],dp[i-1][j][x][y+(1<<(i-1))]);
        }
}

int rmq(int r1,int c1,int r2,int c2) {
    int w = LogTable[c2-c1+1];
    int h = LogTable[r2-r1+1];
    int ans = dp[w][h][r1][c1] ;
    ans = max( ans , dp[w][h][r1][c2-(1<<w)+1] );
    ans = max( ans , dp[w][h][r2-(1<<h)+1][c1] );
    ans = max( ans , dp[w][h][r2-(1<<h)+1][c2-(1<<w)+1] );
    return ans;
}
