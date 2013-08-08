#define SZ 107
int n , m , w[SZ], cnt ;
bool Vis[SZ];

void SumOfSubset(int s,int k,int r)
{
   Vis[k] = true ;
   if(s + w[k] == m ){
       printf("Subset solution %d:\t",++cnt);
       printf("(");
       forab(i,0,k) if( Vis[i] ) printf(" %d",w[i]);
       printf(" )\n");
   }
   else if( s + w[k] + w[k+1] <= m )
        SumOfSubset( s + w[k] , k+1, r - w[k] );

   if( ( s + r - w[k] >= m ) && ( s + w[k+1] ) <= m ){
      Vis[k] = 0;
      SumOfSubset(s , k + 1 , r - w[k] );
   }
}

int main(){
    scanf("%d",&n) ;
    int tot = 0 ;
    rep(i,n) {
        scanf("%d",&w[i]) ;
        tot += w[i] ;
    }
    sort(w,w+n);
    scanf("%d",&m);
    if(tot < m || w[0] > m){
         printf("No solution\n");
    }
    else{
        SumOfSubset(0,0,tot);
        if(!cnt) printf("No solution\n");
    }
}

You have n elements in W array . You have to print all possible solution that can make (m) using those elements .

