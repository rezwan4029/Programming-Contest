#define SZ 100007

const int INF = 1e8;

int N , M , d[SZ] , pred[SZ];
vi Path ;

struct Edge {
    int v, w;
    Edge(){}
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<Edge> E[SZ];

void Init(int s) {
    rep(i,N+1){
        d[i] = INF;
        pred[i] = -1 ;
    }
    d[s] = 0;
}

bool Bellman(int s){
    Init(s);
    bool updated = false ;
    rep(u,N){
        updated = false ;
        if( d[u] == INF ) continue ;
        forstl(it,E[u]) {
            int v = it->v , w = it->w ;
            if (d[v] > d[u] + w ) {
                d[v] = d[u] + w;
                pred[v] = u;
                updated = true ;
            }
        }
        if(!updated)break;
    }
    return ( updated == false );
}

void Input(){
    cin >> N >> M ;
    rep(i,M){
        int u = II , v  = II , w = II ;
        E[u].pb( Edge(v,w) );
    }
}

vi getPath(int u ) { // u = destinition
    Path.clear();
    while( u != -1 ){
        Path.pb(u);
        u = pred[u];
    }
    reverse(all(Path));
    return Path;
}

int main() {
    Input();
    bool ok = Bellman(0) ; // source 0 ** 0 indexed
    if (ok) getPath(N-1); // destinition N-1
    else puts( "Containing negative cycle" );
}
