const int MX = 10007  ;
const int INF = 1e8 + 7;

const int  MAXE = 100007 ;

int src, snk, nNode, nEdge;
int Q[MX], fin[MX], pro[MX], dist[MX];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _n) {
    nNode = _n, nEdge = 0;
    ms(fin,-1);
}
// bidirectional edge **
inline void add(int u, int v, int c) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    ms(dist,-1);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=next[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=next[e]) {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

int dinitz() {
    int ret = 0;
    int df;
    while(bfs()) {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i]; // use temporary source node 0 and main graph 1 to n
        while(true) {
            df = dfs(src, INF);
            if(df) ret += df;
            else break;
        }
    }
    return ret;
}


int main(){
     int n, e ;
     scanf("%d%d", &n, &e);
     init(n);
     rep(i,e){
         int u = II , v  = II ;
         if( u != v ) add(u, v, 1) ;
     }
     src = II ;
     snk = II ;
     int flow = dinitz();
}
