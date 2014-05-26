const int MX = 1e7 + 7 ;
int Mob[MX] ;
void preGen(){
    const int SQ = sqrt(MX) + 1 ;
    int isPrime[SQ+7];
    memset(isPrime,1,sizeof isPrime);
    memset(Mob,0,sizeof Mob);
    for( int i = 2 , j ; i < SQ ;i++) {
        if( isPrime[i]) {
            for ( j = i * i ; j < SQ ; j += i) {
                isPrime[j] = 0;
                Mob[j]= i ;
            }
            for ( ; j <= MX - 7 ; j += i ) Mob[j] = i ;
        }
    }
    //Applying the formula
    //Divisor(N)=Divisors(N/p^f(N,p))*(f(N,p)+1)
    Mob[1] = 1 ;
    for(int i = 2 ; i < MX ; i++ ) {
        if ( Mob[i] == 0 ) Mob[i] = 2 ;
        else {
           int k = i / Mob[i] , cnt = 2 ;
           while ( k % Mob[i] == 0 ) k /= Mob[i] , cnt++ ;
           Mob[i] = Mob[k] * cnt ;
        }
    }
}
