#define SZ 100007

int N , M , d[SZ] , pred[SZ];

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int _u , int _v, int _w) : u(_u) , v(_v), w(_w) {}
};

Edge edges[SZ];

void Init(int s) {
    rep(i,N+1){
        d[i] = INF;
        pred[i] = -1 ;
    }
    d[s] = 0;
}

void relax(int u, int v, int w) {
    if (d[v] > d[u] + w && d[u] != INF ) {
        d[v] = max( -INF , d[u] + w ) ; // handling integer overflow
        pred[v] = u;
    }
}

bool Bellman(int s)
{
    Init(s);
    For(k,N-1) rep(i,M)  relax( edges[i].u , edges[i].v , edges[i].w);
    rep(i,M) if (d[edges[i].v] > d[edges[i].u] + edges[i].w) return false;
    return true;
}

void Input(){
    cin >> N >> M ;
    rep(i,M){
        int u = II , v  = II , w = II ;
        edges[i] =  Edge(u, v, w) ;
    }
}

void printPath(int u ){
    if(u == -1 )return ;
    printPath( pred[u] );
    cout << u << " ";
}

int main() {
    Input();
    bool ok = Bellman(1) ; // source 1
    if (ok){
        printPath(N); // destinition N
    }
    else cout << "Containing negative cycle";
    cout << endl;
}
