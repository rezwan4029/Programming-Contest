#define SZ 2007
int Hist[SZ];

int Histogram(int n)
{
    // Hist has values in 1..to..n
    int top = 1, stk[SZ], ret = 0;
    Hist[0] = stk[0] = Hist[++n] = 0;
    FOR(i,n){
        while( top > 1 && Hist[ stk[ top - 1 ] ] >= Hist[i] ){
             ret = max( ret, Hist[ stk[top - 1 ] ] * ( i - stk[ top - 2 ] - 1 ) );
             top--;
        }
        stk[ top++ ] = i ;
    }
    return ret;
}
