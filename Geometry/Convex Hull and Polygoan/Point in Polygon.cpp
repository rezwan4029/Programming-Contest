
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

