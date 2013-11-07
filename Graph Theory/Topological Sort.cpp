const int MX = 100005;

vi edges[MX], Order; // Order holds the topological ordering
int Indegree[MX] , nV, nE ;
bool MultipleSol ;

void topSort(){
    queue<int>Q;
    For(i,nV) if( Indegree[i] == 0 ) Q.push(i) ;
    while(!Q.empty()){
        if(Q.size() > 1 ) MultipleSol = true ;
        int u = Q.front(); Q.pop();
        forstl(it,edges[u]){
            Indegree[*it]--;
            if( !Indegree[*it ] ) Q.push(*it) ;
        }
        Order.pb(u);
    }
}

void Reset(){
    rep(i,nV+1) edges[i].clear() , Indegree[i] = 0 ;
    Order.clear() , MultipleSol = false ;
}

void Input(){
    cin >> nV >> nE ;
    Reset();
    rep(i,nE){
        int u , v ;
        cin >> u >> v ;
        edges[u].pb(v);
        ++Indegree[v];
    }
}
