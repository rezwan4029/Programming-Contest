// Graph Represnted as adjacancy matrix

#define SZ 105

int n , d[SZ][SZ] , pred[SZ][SZ];

void Reset(){
    For(i,n) For(j,n){
        if(i == j ) d[i][j] = 0 ;
        else d[i][j] = INF ;
        pred[i][j] = -1 ;
    }
}

void Warshall(){
    For(k,n)For(i,n)For(j,n){
            if(d[i][j] > d[i][k] + d[k][j] ){
                d[i][j] = d[i][k] + d[k][j] ;
                pred[i][j] = k ;
            }
    }
}

void PrintPath(int i,int j){
    if(pred[i][j] == -1 ) printf("%d %d -> ",i,j);
    else{
        PrintPath(i,pred[i][j]);
        PrintPath(pred[i][j],j);
    }
}

void Input(){
    n = II ;
    int edges = II ;
    Reset();
    rep(i,edges){
        int u = II , v = II , w = II ;
        d[u][v] = d[v][u] = w ;
    }
}
