long double mat[505][505] ;
vector<long double> gauss( int R , int C)
{
	int i, j, k;

	for (i = 0; i < R; i++) {
		k = i;
		for (j = i+1; j < C; j++) if ( fabs(mat[j][i]) > fabs(mat[k][i]) ) k = j;
		if (k != i) for (j = 0; j <= C; j++) swap(mat[k][j], mat[i][j]);
		for (j = i+1; j <= C; j++) mat[i][j] /= mat[i][i];
		mat[i][i] = 1;
		for (k = 0; k < R; k++) if( k != i ) {
			long double t = mat[k][i];
			if (t == 0.0L) continue;
			for (j = i; j <= C; j++) mat[k][j] -= t * mat[i][j];
			mat[k][i] = 0.0L;
		}
	}
  vector<long double>sol;
	rep(i,R) sol.pb(mat[i][C]);
	return sol;
}

int main()
{
    int equations ,variables;

    while(cin >> equations >> variables )
    {
        rep(i,equations)rep(j,variables+1) cin >> mat[i][j] ;

        vector<long double>ret = gauss(equations,variables);
        int k = 1 ;
        forstl(it,ret) { printf( "x[ %d ]  = ",k++) ; cout  << *it  << endl;}
    }
}

/*
3 3
1 1 -1 9
0 1 3 3
-1 0 -2 2
x = 0.666667 , y = 7 , z = -1.33333
*/
