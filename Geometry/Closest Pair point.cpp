const int SZ = 100010 ;

point a[SZ];
double minDist;
int N ;

bool cmp_x( point a , point b){
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmp_y( point a , point b){
	return a.y < b.y;
}

void Update( point a , point b) {
	double dist = a.dis(b) ;
	if (dist < minDist) minDist = dist ;
}

void solve (int l, int r) {
	if(r - l <= 3 ){
        forab(i,l,r) forab(j,i+1,r) Update( a[i] , a[j]);
		sort (a+l, a+r+1,cmp_y);
		return;
	}
	int m = (l + r) >> 1;
	double midX = a[m].x;
	solve (l, m),  solve (m+1, r);
	static point t[SZ];
	merge (a+l, a+m+1, a+m+1, a+r+1, t,cmp_y);
	copy (t, t+r-l+1, a+l);
	int tsz = 0;
	forab(i,l,r){
		if ( fabs (a[i].x - midX ) < minDist) {
			for (int j = tsz-1 ; j>=0 && a[i].y - t[j].y < minDist ; j--) Update(a[i], t[j]);
			t[tsz++] = a[i];
		}
	}
}

void Closest_Pair(){
    sort(a,a+N,cmp_x);
    minDist = 1E20 ;
    solve(0,N-1);
}
