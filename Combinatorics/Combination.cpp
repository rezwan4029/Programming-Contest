#define MX 30

Long nCr[MX][MX];

void combination() {
	nCr[0][0] = 1;
	For(i , MX - 1 ) {
		nCr[i][0] = 1;
		For(j,i) nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] )  ;
	}
}

