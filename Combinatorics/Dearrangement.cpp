#define SZ 30

ll darG[SZ];

void fnc()
{
    darG[1] = 0 , darG[2] = 1 ;
    forab(n , 3 , SZ - 1 ) darG[i] = (n - 1 ) * ( darG[n-1] + darG[n-2] ) ;
}

