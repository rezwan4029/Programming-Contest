//all are 1 indexed Graph

const int MX = 10005;
vi adj[MX],Radj[MX],order,Comp;
bool used[MX];
int newCompId[MX];
int N , M;

void dfs1(int u) {
    used[u] = true ;
    forstl(it,adj[u]) if( !used[ *it ] ) dfs1( *it );
    order.pb(u);
}

void dfs2(int u , int scc ){
    newCompId[u] = scc ;
    used[u] =  true ;
    Comp.pb(u);
    forstl(it,Radj[u]) if( !used[ *it ] ) dfs2( *it , scc );
}

void Reset(){
    For(i,N){
        adj[i].clear();
        Radj[i].clear();
    }
    ms(newCompId,false);
    ms(used,false);
    order.clear();
}

void Input(){
    cin >> N >> M ;
    rep(i,M){
        int u = II , v = II ;
        adj[u].pb(v);
        Radj[v].pb(u);
    }
}

void Zip(){
    reverse(all(order));
    int scc = 0 ;
    forstl(it,order){
        int v = *it ;
        if( !used[ v ] ){
            scc++;
            Comp.clear();
            dfs2(v,scc);
            printf("No.%d SCC components are ->  ",scc);
            forstl(u,Comp) printf(" %d",*u);
            puts("");
        }
    }
}

void Kosaraju(){
    For(i,N) if( !used[i] ) dfs1(i);
    ms(used,false);
    Zip();
}

int main(){
    //freopen("in.txt", "r", stdin);
    Input();
    Kosaraju();
    Reset();
}
