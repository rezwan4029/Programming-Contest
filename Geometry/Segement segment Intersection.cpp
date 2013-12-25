int turn( point O , point A , point B){ 
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

inline bool onsegment(const point &p1, const point &p2, const point &p3) {
    point pmn, pmx;
    pmn.x = min(p1.x, p2.x), pmn.y = min(p1.y, p2.y);
    pmx.x = max(p1.x, p2.x), pmx.y = max(p1.y, p2.y);
    return pmn.x <= p3.x && p3.x <= pmx.x && pmn.y <= p3.y && p3.y <= pmx.y;
}

inline bool Intersect(const point &p1, const point &p2, const point &p3, const point &p4, bool &on) {
    ll d1, d2, d3, d4;
    d1 = turn(p3, p4, p1);
    d2 = turn(p3, p4, p2);
    d3 = turn(p1, p2, p3);
    d4 = turn(p1, p2, p4);
    on = false;
    if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
    if( !d3 && onsegment(p1, p2, p3)) { on = true; return true; }
    if( !d4 && onsegment(p1, p2, p4)) return true;
    if( !d1 && onsegment(p3, p4, p1)) return true;
    if( !d2 && onsegment(p3, p4, p2)) return true;
    return false;
}


/*******************************************************************************************************************/

struct Seg { point s, e; };

int SegmentIntersection(Seg a, Seg b, point &p) {
    double a1 = a.s.y - a.e.y, b1 = -a.s.x + a.e.x;
    double a2 = b.s.y - b.e.y, b2 = -b.s.x + b.e.x;
    double c1 = a1 * a.s.x + b1*a.s.y;
    double c2 = a2 * b.s.x + b2*b.s.y;
    double D =  a1 * b2  - a2 * b1;
    double Dx = c1 * b2  - c2 * b1;
    double Dy = a1 * c2  - a2 * c1;
    if( fabs(D) < EPS ) return 0; // NONE or LINE
    p.x = Dx/D , p.y = Dy/D;
    return onsegment(a.s , a.e , p) && onsegment(b.s , b.e , p) ;
}
