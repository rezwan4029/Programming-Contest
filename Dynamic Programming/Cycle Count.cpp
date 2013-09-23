int N , M ;

ll dp[20][1<<20];
bool Vis[20][1<<20];
bool mat[20][20];

ll solve(int masK , int currNode , int startNode, int nVisited){
    ll &ret = dp[currNode][masK];
    if(Vis[currNode][masK])return ret ;
    Vis[currNode][masK] = true ;
    ret = 0 ;
    ret += ( (nVisited >= 2 ) && (mat[currNode][startNode] == true ) );
    forab( i , startNode + 1 , N-1 ){
       if( (masK & (1<<i)) || mat[currNode][i] == false ) continue ;
       ret += solve( masK|1<<i , i , startNode , nVisited+1 );
    }
    return ret ;
}

int main(){
    cin >> N >> M ;
    ms(mat,false) , ms(Vis,false);
    rep(i,M){
        int x = II - 1 , y = II - 1 ;
        mat[x][y] = mat[y][x] = true ;
    }
    ll nCycles = 0 ;
    rep(i,N){
        nCycles += solve( 1 << i , i , i , 0 ) ;
    }
    printf("%lld\n",nCycles/2);
}
