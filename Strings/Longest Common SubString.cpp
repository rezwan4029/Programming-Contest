struct state {
	int len, link ;
	map < char , int > next ;
};

const int MAXLEN = 250002 ;
state st [ MAXLEN * 2 ] ;
int sz, last ;

void sa_init ()
{
	sz = last = 0 ;
	st [ 0 ] . len = 0 ;
	st [ 0 ] . link = - 1 ;
	sz++ ;
	/*
	// This is needed only if the machine is constructed many times for different lines:
	for (int i=0; i<MAXLEN*2; ++i)
		st[i].next.clear();
	*/
}

void sa_extend ( char c ) {

	int cur = sz ++ ;
	st [ cur ] . len = st [ last ] . len + 1 ;
	int p ;
	for ( p = last ; p != - 1 && !st [ p ] . next . count ( c ) ; p = st [ p ] . link )
		st [ p ] . next [ c ] = cur ;
	if ( p == - 1 )
		st [ cur ] . link = 0 ;
	else {
		int q = st[p].next [c] ;
		if ( st [p].len + 1 == st [q].len )
			st[cur].link = q ;
		else {
			int clone = sz ++ ;
			st [ clone ] . len = st [ p ].len + 1 ;
			st [ clone ] . next = st [ q ].next ;
			st [ clone ] . link = st [ q ].link ;
			for ( ; p != - 1 && st [ p ].next [ c ] == q ; p = st [p].link )
				st [p] . next [c] = clone ;
			st [q].link = st [cur].link = clone ;
		}
	}
	last = cur ;
}

string lcs ( string s, string t ) {
	sa_init ( ) ;
	int slen = s.length() , tlen = t.length() ;
	rep(i,slen) sa_extend ( s [ i ] ) ;
	int v = 0 ,  l = 0 , best = 0 ,  bestpos = 0 ;
	rep(i,tlen)
	{
		while ( v && ! st [ v ] . next.count ( t[i] ) ) {
			v = st [v].link ;
			l = st [v].len ;
		}
		if ( st [v] . next.count ( t[i] ) ) {
			v = st [v].next [ t [i] ] ;
			++l ;
		}
		if ( l > best ) best = l,  bestpos = i ;
	}
	return t. substr ( bestpos - best + 1 , best ) ;
}

char a[MAXLEN] , b[MAXLEN] ;
int main(){
    scanf("%s %s",&a,&b);
    printf("%d\n",lcs(a,b).length());

}

