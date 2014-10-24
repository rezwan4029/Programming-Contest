#define MX 5050
const Long INF = 1e17 ;

struct NODE{
    Long v,Cap,Cost,RevInd;
    // This ind is necessary for multi graph to know which edge is used to take flow
};
vector<NODE>Edge[MX];
Long nV,nE,P;
Long SRC,TNK;
// This PInd is necessary for multi graph to know which edge ind of parent is used to take flow
Long Par[MX],PInd[MX];
Long SD[MX];// Shortest path
void SetEdge( Long u,Long v,Long Cap,Long Cost ) {
    NODE U ={ v, Cap, +Cost, Edge[v].size() };
    NODE V ={ u, 0  , -Cost, Edge[u].size() };
    Edge[u].push_back(U);
    Edge[v].push_back(V);
}
bool BFord() {
    forab(i,SRC,TNK) Par[i] = -1 , SD[i] = INF ;
    bool IsChange = true;
    SD[SRC] =0;
    while( IsChange ){
        IsChange =false;
        forab(u,SRC,TNK) {
            rep(i,(int)Edge[u].size()){
                if( !Edge[u][i].Cap ) continue;
                Long v = Edge[u][i].v;
                Long TD = SD[u] + Edge[u][i].Cost ;
                // relaxation
                if( SD[v] > TD ){
                    SD[v] = TD ; Par[v] = u ; PInd[v] = i ;
                    IsChange = true;
                }
            }
        }
    }
    return Par[TNK]!=-1;
}
Long FindVol( Long s,Long t) {
    Long Cap =Edge[ Par[t]][ PInd[t]].Cap;
    if( s == Par[t] ) return Cap;
    else return min( Cap,FindVol( s,Par[t]));
}
Long AugmentPath( Long s,Long t,Long V) {
        if( s==t ) return 0;
        Long Cost = Edge[ Par[t] ][ PInd[t] ].Cost*V;
        Edge[ Par[t]][ PInd[t]].Cap -=V;
        Edge[ t ][ Edge[ Par[t] ][ PInd[t] ].RevInd ].Cap += V;
        return Cost + AugmentPath( s,Par[t],V);
}
void MinCost( Long &Flow,Long &Cost) {
    Flow = Cost = 0;
    while( BFord() ){
        Long V = FindVol( SRC,TNK );
        Flow +=V;
        Cost +=AugmentPath( SRC,TNK,V);
    }
}
Long DataFlow ; // how much flow I want to send
void Input(){
	rep(i,nE){
		int u = II , v = II , cap = II , cost = II ;
		SetEdge(u,v,cap,cost);
		SetEdge(v,u,cap,cost);
	}
	SRC = 0 ;
	TNK = nV + 1 ;
	SetEdge(0,1,DataFlow,0);
	SetEdge(nV,TNK,DataFlow,0);
}
int main(){
	int T = II ;
	For(cs,T){
		scanf("%lld %lld %lld",&nV,&nE,&DataFlow);
		rep(i,MX-2) Edge[i].clear();
		Input();
		Long Flow, Cost ;
		MinCost(Flow,Cost);
		printf("Case %d: ",cs);
		if(Flow == DataFlow ) printf("%lld\n",Cost);
		else puts("impossible");
	}
}
