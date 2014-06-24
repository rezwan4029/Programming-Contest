#define MX 100007
struct edge{
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
};

bool operator < ( edge a ,edge b){  return a.w < b.w ; }

int par[MX];

int Parent(int i){
    if(i==par[i])return i;
    return ( par[i] = Parent( par[i] ) );
}

int isUnion(int a,int b){
    return Parent(a) == Parent(b);
}

void makeUnion(int a,int b ){
    par[ Parent(a) ] = Parent(b);
}

int MST(int n , edge *x , int e ){
  sort(x,x+e);
  rep(i,n) par[i] = i ;
  int mst = 0 , spanning_edges = 0 ;
  rep(i,e){
        if(!isUnion(x[i].u,x[i].v)){
            makeUnion(x[i].u,x[i].v);
            mst += x[i].w;
            spanning_edges ++ ;
        }
   }
   return mst ; // if(spanning edges == n - 1 )
}

int main(){
    edge Ed[MX];
    int n , m  ;
    scanf("%d %d",&n,&m);
    rep(i,m){
        int u , v , w ;
        scanf("%d %d %d",&u,&v,&w);
        Ed[i] = edge(u,v,w);
    }
    printf("%d\n",MST(n,Ed,m)) ;
}
