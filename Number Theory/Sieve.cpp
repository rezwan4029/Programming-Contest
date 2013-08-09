#define PrimeLIMIT 5000100
#define MAX_TOTAL 350000

ll prime[PrimeLIMIT / 64], pr[MAX_TOTAL], prlen;

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve() {
	memset( prime, -1, sizeof( prime ) );
	ll sqrtN = (ll) sqrt ( ( double ) PrimeLIMIT ) + 1;
	
	for(ll i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
		for( ll j = i * i, i2 = i << 1; j < PrimeLIMIT; j += i2 ) rP( j );
	
	pr[prlen++] = 2;
	for(ll i = 3; i < PrimeLIMIT; i += 2 ) if( gP( i ) ) pr[ prlen++ ] = i;
}