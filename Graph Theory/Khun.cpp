#define MX 205
vi edges[MX];
int L[MX], R[MX];
int N, M ;
bool Vis[MX];

void clear()
{
     rep(i,MX) edges[i].clear() , L[i] = R[i] = -1 ;
}
void input()
{
     cin >> N >> M ;
}
void makeGraph()
{
    //edges[i].push_back( j + N );
}

bool match(int u) {
     forstl(it,edges[u]) {
         int v = *it;
         if( Vis[v] ) continue ;
         Vis[v] = true;
         if( R[v] == - 1 || match( R[v]  ) == true) {
             R[v] = u;
             L[u] = v ;
             return true;
         }
     }
     return false ;
}
int bipartiteMatch() {
   int Mtch = 0 ;
   while(true) {
        ms( Vis, false );
        bool foundMatch = false ;
        rep(i,N) {
            if( L[i] != -1 ) continue;
            if( match(i) ) foundMatch = true , Mtch++ ;
        }
        if( foundMatch == false ) break;
   }
   return Mtch ;
}
int main() {
      clear();
      input();
      makeGraph();
      int Ans = bipartiteMatch();
}
