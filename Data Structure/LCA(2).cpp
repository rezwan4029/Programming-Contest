const int MX = 1e6 + 7 ;
const int MXLG = 22 ;
const int INF = 1e8 + 7;
vector<pii>edge[MX] ;
int N , P[MX][MXLG] , L[MX] ;
int dist[MX] , diameter ;
pii leaf ; // two furthest leaf of the tree
void preprocess(int u) {
    for( int j = 1 ; (1 << j) <= N ; j++ ) {
            if( P[u][j - 1] == -1 ) continue ;
            P[u][j] = P[ P[u][j - 1] ][j - 1];
    }
}
void addLeaf(int u , int par , int cost ) {
    P[u][0] = par ;
    L[u] = L[par] + 1 ;
    dist[u] = dist[par] + cost ;
    N++;
    preprocess(u);
}
int lca(int p , int q){
    if(L[p] < L[q] ) swap(p,q);
    int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
    for( int i = lg ; i >= 0 ; i--){
        if( L[p] - (1 << i) >= L[q] ){
            p = P[p][i];
        }
    }
    if( p == q ) return p ;
    for( int i = lg ; i >= 0 ; i-- ){
        if( P[p][i] != -1 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return P[p][0];
}
int getDistance(int x , int y){
    int a = lca(x,y);
    int Ans = dist[x] + dist[y] - 2 * dist[a] ;
    return Ans;
}
void updateDiameter(int u , int par ) { /** u = new leaf :: par = parent of that new leaf **/
    if( par == leaf.ff || par == leaf.ss ) {
        par == leaf.ff ? leaf.ff = u : leaf.ss = u ;
        diameter++;
    }
    else{
        int d1 = getDistance(leaf.ff,par);
        int d2 = getDistance(leaf.ss,par);
        d1++ , d2++ ;
        if( d1 > d2 ){
            if( d1 > diameter ){ leaf.ss = u ; diameter = d1 ; }
        }else {
            if( d2 > diameter ){ leaf.ff = u ; diameter = d2 ; }
        }
    }
}
int main(){
    memset(P,-1,sizeof P);
    N = 1 ; L[1] = dist[1] = 0 ;
    /** N = 1 when only root available :: level and distance of root is 0 **/
    /** set the two furthest leaf **/
    int q = II ;
    while( q-- )
    {
        int v ; read(v);
        int x = N + 1 ; /** new Node N+1 is added **/
        addLeaf(x,v,1);
        updateDiameter(x,v);
        printf("%d\n",diameter);
    }
}
