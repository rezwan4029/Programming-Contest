/*
 * Biconnected components, bridges and articulation points of
 * undirected graphs
 */

#define MX 10001

int N,M,counter, seen[MX], low[MX];
vector<int>adj[MX],stk;

void dfs(int u, int par) {
    int children = 0, art = 0;
    low[u] = seen[u] = ++counter;
    stk.pb(u);
    forstl(it,adj[u]) {
        int v = *it;
        if (v == par) continue;
        if ( !seen[v] ) {
            dfs(v,u);
            children++;
            low[u] = min(low[u], low[v]);
            if( low[v] >= seen[u] ) {
                printf("%d is an articulation point.\n",u);
            }
            if (low[v] == seen[v]) printf("Edge (%d, %d) is a bridge.\n", u, v);
        }
        else {
            low[u] = min(low[u], seen[v]);
        }
    }

    /** root of DFS is an articulation point if it has more than 1 child */
    if (par == -1 && children > 1 ) {
        printf("%d is an articulation point.\n",u);
    }

    if (low[u] == seen[u]) {
        printf("Biconnected component:");
        while (true) {
            int v = stk.back();
            stk.pop_back();
            printf(" %d", v);
            if (v == u) break;
        }
        printf("\n");
    }
}

void Reset(){
    memset(seen, 0 ,sizeof seen );
    counter = 0;
    stk.clear();
    rep(i,N+1) adj[i].clear();
}

int main(){
    cin >> N >> M;
    Reset();
    rep(i,M){
        int x = II , y = II ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    For(i,N)if(seen[i] == 0) dfs(i, -1);
}
