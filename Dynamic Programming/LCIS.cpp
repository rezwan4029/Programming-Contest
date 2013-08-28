#define SZ 10000

vector<int>seq[2];
int dp[SZ] , path[SZ] , ans[SZ] ;

int LCIS()
{
    int S1 = seq[0].size() , S2 = seq[1].size();
    memset(dp,0,sizeof dp);
    int  n , p ;
    rep(i,S1){
        n = 0 , p = -1;
        rep(j,S2){
            if(seq[0][i] == seq[1][j] && n+1 > dp[j] ){
                    dp[j] = n+1;
                    path[j] = p;
            }
            if(seq[1][j] < seq[0][i] && n < dp[j] ){
                    n = dp[j];
                    p = j;
            }
        }
    }
    n = 0 , p = -1;
    rep(i,S2) if( dp[i] > n ) n = dp[ p = i ];

    // return n if path not need

    for(int i = n-1 ; i>=0 ;--i ){
            ans[i] = seq[1][p] ;
            p = path[p];
    }

    return n;
}
int main(){
    int n = II ;
    rep(i,n) seq[0].pb(II);
    int m = II ;
    rep(i,m) seq[1].pb(II);
    int s = LCIS();
    cout << "LCIS len = " << s << endl ;
    rep(i,s) cout << ans[i] << " ";
}
