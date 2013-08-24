#define SZ 10005
struct Edge{
    int u , v , cost;
    Edge(){}
    Edge(int x ,int y ,int z){
        u =x , v = y , cost = z ;
    }
};

int pre[SZ],ID[SZ],vis[SZ];
int In[SZ];
Edge E[SZ] ;

int ChuLiu(int root,int n,int e)
{
    int ret = 0;
    while(true) { //1. Find the smallest edge
         rep(i,n) In[i] = INF;
         rep(i,e){
            int u = E[i].u , v = E[i].v;
             //This step, you can cut off the ring, identifying each point minimum to edge
            if(E[i].cost < In[v] && u != v) {
                pre[v] = u;
                In[v] = E[i].cost;
            }
         }
         rep(i,n) {
            if(i == root) continue;
            if(In[i] == INF)    return -1; //Except a little not into, you cannot reach it
         }
         //2. ring
         int  CntNode  = 0;
         ms( ID , -1 ) ;
         ms( vis ,  -1 ) ;
         In[root] = 0;
         rep(i,n){    //Mark each ring
            ret += In[i];
            int v = i;
            while(vis[v] != i && ID[v] == -1 && v != root) {
                    vis[v] = i;
                    v = pre[v];
                    //vis is marked for all nodes in the ring into the edges
                    // of the points below, 1 1,2,3,4,5,6 are marked as
            }
            if(v != root && ID[v] == -1) {
                for(int u = pre[v] ; u != v ; u = pre[u]) {
                        ID[u] =  CntNode ;
                }
                ID[v] =  CntNode++ ;
            }
        }
        if( CntNode  == 0)  break ;//No ring
        rep(i,n) if(ID[i] == -1) {
            ID[i] =  CntNode++ ;
        }
        //3. reduced points, Relabel, adjustments into the weights of the edges of the ring,
        // so that the next round of the cycle identified the minimum edge
        rep(i,e) {
            int v = E[i].v;
            E[i].u = ID[ E[i].u ] , E[i].v = ID[ E[i].v ];
            if(E[i].u != E[i].v)  E[i].cost -= In[v];
        }
        n =  CntNode ;
        root = ID[root];
    }
    return ret ;
}

int main(){
    int nodes = II , nEdges = II , source = II ;
    rep(i,nEdges){
            int u = II ,v = II ,w = II ;
            E[i] = Edge( u ,v ,w );
    }
    int ans = ChuLiu(source ,nodes , nEdges) ;
    ans == -1 ? puts("MST cant be made") : printf("%d\n",ans);
}
