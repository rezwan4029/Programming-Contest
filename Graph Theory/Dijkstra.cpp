#define SZ 100007

int N , M , pred[SZ] , d[SZ] ;
bool Vis[SZ];

struct Node{
    int v , w ;
    Node(){}
    Node(int _v , int _w){
        v = _v , w = _w ;
    }
    bool operator <(const Node &a) const{
        if (w != a.w) return (w > a.w);
        return (v > a.v);
    }
};

vector<Node>adj[SZ];

void Reset(){
    rep(i,N+1) {
        adj[i].clear();
        d[i] = pred[i] = -1 ;
        Vis[i] = false ;
    }
}

void Dijstra(int src){
    priority_queue<Node>Q;
    d[src] = 0 ;
    Q.push( Node(src,0) );
    while(!Q.empty()){
        Node now = Q.top(); Q.pop();
        int currNode = now.v , currCost = now.w ;
        if(Vis[currNode])continue;
        Vis[currNode] = true ;
        forstl( it , adj[currNode] ){
            int nxtNode = it->v , nxtCost = it->w ;
            if( currCost + nxtCost < d[nxtNode] || d[nxtNode] == -1 ){
                d[nxtNode] = currCost + nxtCost ;
                Q.push( Node( nxtNode , d[nxtNode] ) );
                pred[nxtNode] = currNode ;
            }
        }
    }
}

void Input(){
    cin >> N >> M ;
    Reset();
    rep(i,M){
        int u = II , v = II , w = II ;
        adj[u].pb( Node(v,w) );
        adj[v].pb( Node(u,w) );
    }
}

void printPath(int u ){
    if(u == -1 )return ;
    printPath( pred[u] );
    printf("%d ",u);
}

int main(){
    Input();
    Dijstra(1); // source node 1
    if( d[N] == -1 ) puts("-1");
    else printPath(N) ; // destination node N
}
