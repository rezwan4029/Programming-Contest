/*
 * Algorithm : Point in Polygon By ray shooting
 *             Adapted from "Computational Geometry in C" (Second Edition)
 * Complexity : O( N )
 * Note : For each query point Pt, InPoly returns one of four char's:
 *	i : Pt is strictly interior to Pl
 *  o : Pt is strictly exterior to Pl
 *	v : Pt is a vertex of Pl
 *	e : Pt lies on the relative interior of an edge of Pl
 *
*/


/* type integer point */

char PointInPoly( point Pt,point *Pl, long N ){
    long Rcross = 0; /* number of right edge/ray crossings */
    long Lcross = 0; /* number of left edge/ray crossings */

    /* Shift so that Pt is the origin. Note this destroys the polygon.*/
    rep(i,N){
        Pl[i].x = Pl[i].x - Pt.x ;
        Pl[i].y = Pl[i].y - Pt.y ;
    }
    /* For each edge e=(i-1,i), see if crosses ray. */
    rep(i,N){
        /* First see if Pt=(0,0) is a vertex. */
        if( Pl[i].x==0 and Pl[i].y==0 ) return 'v';
        long j = (i+N-1)%N;

        bool Rstrad = (Pl[i].y>0) != (Pl[j].y>0);
        bool Lstrad = (Pl[i].y<0) != (Pl[j].y<0);

        /* if e "straddles" the x-axis... */
        if( Rstrad or Lstrad ){
            /* e straddles ray, so compute intersection with ray. */
            double x = ( Pl[i].x*(double)Pl[j].y - Pl[j].x*(double)Pl[i].y) / (double)(Pl[j].y-Pl[i].y);
            /* crosses ray if strictly positive intersection. */
            if( Rstrad and x>0 ) Rcross++;
            if( Lstrad and x<0 ) Lcross++;
        }
    }
    /* Pt on the edge if left and right cross are not the same parity. */
    if( (Rcross%2) != (Lcross%2) ) return 'e';
    /* Pt inside iff an odd number of crossings. */
    if( (Rcross%2) == 1 ) return 'i';
    else return 'o';
}



/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

struct point {
    double x,y;
    point(){
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    point (const point &p) {
        x = p.x, y = p.y;
    }
    void translate(double tx, double ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(point k){
        return point(x + k.x , y + k.y );
    }
    point operator-(point k){
        return point(x - k.x , y - k.y );
    }
    point operator*(double k) {
        return point(k * x , k * y );
    }
    point operator/(double k) {
        return point(x / k , y/k );
    }
    point rotleft(){
        return point(-y,x);
    }
    point rotright(){
        return point(y,-x);
    }
    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
    #define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const {
        return ((x==p.x) && (y==p.y));
    }
    bool collinear(const point &p1, const point &p2)const  {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }

    inline double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    inline double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }
    bool in_box(const point &a, const point &b) const { // rectangle : a = leftDown , b = rightTop
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x >= lox && x <= hix && y >= loy && y <= hiy; // remove = (eq) if strictly in box need
    }

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

vector<point>P;
int N ;

int turn( point O , point A , point B){ //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}


//faster check ** point should be strictly inSide of polygon
bool PointInsideConvexPoly(point p){
	int a = 1, b = P.size()-1, c;
	if (turn(P[0], P[a], P[b]) > 0) swap(a,b);
	if (turn(P[0], P[a], p) >= 0 || turn(P[0], P[b], p) <= 0) return false;
	while(abs(a-b) > 1) {
		c = (a+b)/2;
		if (turn(P[0], P[c], p) > 0) b = c; else a = c;
	}
	return turn(P[a], P[b], p) < 0;
}
