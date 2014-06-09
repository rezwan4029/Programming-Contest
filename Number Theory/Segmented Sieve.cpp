/**
    Your are given two integers a and b. You have to find all the primes within range a and b.
    Here, 1 ≤ a ≤ b ≤ 2^31-1 and b - a ≤ 10^6.
    Note: You have to handle 1, 2 and even numbers for appropriate case of your own.
*/

#define MX 46656
#define LMT 216
#define LEN 4830
#define RNG 1000032

unsigned base[MX/64], seg[RNG/64], pr[LEN];

#define chkC(x,n) (x[n>>6] & (1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6] |=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve() {
    unsigned long i, j, k;
    for(i = 3; i < LMT ; i += 2 )
        if( !chkC(base, i) )
            for( j = i*i , k = i<<1; j < MX ; j += k ) setC(base, j);
    for(i = 3, j = 0 ; i < MX; i += 2 ) if( !chkC(base, i) ) pr[j++] = i;
}

/* Returns the primes within range [a,b] and marks them in segment[] */
vector<Long> segmented_sieve(Long a , Long b) {
    vector< Long > Ans;
    unsigned long i, j, k ;
    if( b < 2 ) return Ans;
    if( a <= 2 ) Ans.push_back( 2 );
    if( a < 3 ) a = 3;
    if( a % 2 == 0 ) a++;
    memset(seg,0,sizeof seg);
    for( i = 0 ; pr[i] * pr[i] <= b; i++) {
        j = pr[i] * ( ( a + pr[i]-1) / pr[i] );
        if( j % 2 == 0 ) j += pr[i];
        for(k = pr[i]<<1 ; j <= b; j += k )
            if( j != pr[i] ) setC(seg, (j-a));
    }
    for(i = 0 ; i <= b - a ; i += 2 )
        if( !chkC(seg,i) ) Ans.push_back( i + a );
    return Ans;
}

int main(){
    sieve();
    Long a , b ;
    while( cin >> a >> b ) vector<Long> g = segmented_sieve( a , b ) ;
}
