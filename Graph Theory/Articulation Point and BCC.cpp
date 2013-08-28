/*
 * Biconnected components, bridges and articulation points of
 * undirected graphs
 */

#define SZ 10001

int N,M,counter, seen[SZ], low[SZ];
vector<int>adj[SZ],stk;

void dfs(int u, int par)
{
    int kids = 0, art = 0;
    low[u] = seen[u] = ++counter;

    stk.pb(u);

    forstl(it,adj[u])
    {
        int v = *it;
        if (v == par) continue;
        if (seen[v] == 0)
        {
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            art |= (low[v] >= seen[u]);
            kids++;
            if (low[v] == seen[v]) printf("Edge (%d, %d) is a bridge.\n", u, v);
        }
        else
        {
            low[u] = min(low[u], seen[v]);
        }
    }

    if (par == -1) art = (kids >= 2);

    if (art) printf("Vertex %d is an articulation point.\n", u);

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
    rep(i,M){
        int x = II , y = II ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    For(i,N)if(seen[i] == 0) dfs(i, -1);
    Reset();
}
