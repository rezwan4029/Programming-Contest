const int MX = 100007 ;
vector<int> pr ;
int BT[MX/64];
void sieve() {
    memset( BT , -1, sizeof BT );
    #define gP(n) ( BT[n>>6] &  (1<<((n>>1)&31) ) )
    #define rP(n) ( BT[n>>6] &=~(1<<((n>>1)&31) ) )
    int SQ = sqrt (MX) + 1;
    for(int i = 3 ; i < SQ; i += 2 ) if( gP( i ) )
            for( int j = i * i , k = i * 2 ; j < MX; j += k ) rP( j );
    pr.push_back(2);
    for(int i = 3; i < MX; i += 2 )
        if( gP( i ) ) pr.push_back(i) ;
}

int Factors[MX/2];
void Factorize( int n ){ // Factor[i] = x ;  means N! has x number of time pr[i] as its factor
    memset(Factors,0,sizeof Factors);
    for( int i = 0 ; pr[i] <= n ; i++ ){
        for( int j = pr[i] ; j <= n ; j *= pr[i] ){
            Factors[i] += n/j ;
        }
    }
}
