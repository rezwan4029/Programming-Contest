enum { WHITE = 0 , BLACK , RED };

const int MX = 100005;

vi edges[MX] ;
int nV, nE , Vis[MX] ;
bool foundCycle ;

void Dfs(int u ){
    Vis[u] = BLACK ;
    forstl(it,edges[u]){
        if( Vis[*it] == WHITE ) Dfs(*it);
        else if( Vis[*it] == BLACK ) {
            foundCycle = true ; return ;
        }
    }
    Vis[u] = RED ;
}


void Input(){
    cin >> nV >> nE ;
    rep(i,nV+1) edges[i].clear() , Vis[i] = WHITE ;
    foundCycle = false ;
    rep(i,nE){
        int u , v ;
        cin >> u >> v ;
        edges[u].pb(v);
    }
}
