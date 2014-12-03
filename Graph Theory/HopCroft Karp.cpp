const int MX = 2e5 + 7 ;
#define INF 7777777
#define NIL 0

vi G[MX];
int n, m, match[MX], dist[MX];

// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] G1[G[1---n]] G2[G[n+1---n+m]]

bool bfs() {
    queue<int>Q;
    For(i,n) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if( u != NIL) {
            forstl(i,G[u]) {
                int v = *i;
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    if(u != NIL) {
        forstl(i,G[u]) {
            int v = *i;
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int hopcroft_karp() {
    int matching = 0 ;
    forab(i,0,2*n) match[i] = NIL;
    // match[] is assumed NIL for all vertex in G
    while(bfs()) {
        For(i,n)
        if(match[i] == NIL && dfs(i)) matching++;
    }
    return matching;
}
void Reset() {
    For(i,2*n) G[i].clear();
}
void Input() {
    Reset();
    cin >> n >> m ;
    while( m-- ) {
        int u = II + 1, v = II + 1 ;
        G[u].pb( n + v );
       // G[v].pb( n + u );
    }
}
int main() {
    Input();
    int ans = hopcroft_karp();
}
