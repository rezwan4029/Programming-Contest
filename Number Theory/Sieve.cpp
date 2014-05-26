const int MX = 1e6 + 7 ;
vector<int> pr ;
bool isPrime[MX];
int BT[MX/64];
void sieve() {
    memset( BT , -1, sizeof BT );
    #define gP(n) ( BT[n>>6] &  (1<<((n>>1)&31) ) )
    #define rP(n) ( BT[n>>6] &=~(1<<((n>>1)&31) ) )
    int SQ = sqrt (MX) + 1;
    for(int i = 3 ; i < SQ; i += 2 ) if( gP( i ) )
            for( int j = i * i , k = i * 2 ; j < MX; j += k ) rP( j );
    pr.push_back(2);
    isPrime[2] = true ;
    for(int i = 3; i < MX; i += 2 )
        if( gP( i ) ) pr.push_back(i) , isPrime[i] = true ;
}
