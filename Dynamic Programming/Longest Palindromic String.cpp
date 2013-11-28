const int MX = 1010 ;
string s ;
int n , dp[MX][MX];

string solve() {

    n = s.size() ;

    forab(i,0,n) dp[i][0] = dp[0][i] = i;

    rep(i,n)  rep(j,n-i-1)
        dp[i + 1][j + 1] = ( s[i] == s[n - 1 - j] ) ? dp[i][j] : min( dp[i][j + 1] + 1, dp[i + 1][j] + 1 );

    int mn = n , x = 0 ,  y = n;

    forab(i,0,n){
      if (mn > dp[i][n - i]) {
            mn = dp[i][n - i];
            x = i;
            y = n - i;
      }
    }

    string middle = "" , res = "" , ans = "" ; // must initialize

    rep(i,n){
      if (mn > dp[i][n - i - 1]) {
        mn = dp[i][n - i - 1];
        x = i;
        y = n - i - 1;
        middle =  s[i];
      }
    }

    while (x > 0 && y > 0) {
      int a = dp[x - 1][y - 1];
      int b = dp[x - 1][y];
      int c = dp[x][y - 1];
      int m = min(a, min(b, c));
      if (m == a) {
        res += s[x - 1] ;
        --x;
        --y;
      } else if (m == b) {
        --x;
      } else {
        --y;
      }
    }
    ans = res ;
    reverse(all(res));
    ans = res + middle + ans ;
    return ans ;
}

int main(){
    cin >> s ; // "3213" :: ans -> 323
    cout << solve() << endl;
}
