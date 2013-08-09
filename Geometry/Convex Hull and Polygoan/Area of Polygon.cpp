double poly_area( vector<point>P){ 
    double res = 0 , x1 ,y1,x2,y2;
    for( int i = 0 , sz = P.size() ; i < sz ; i++ ){
            x1 = P[i].x , x2 = P[(i+1)%sz].x;
            y1 = P[i].y , y2 = P[(i+1)%sz].y;
            res += ( x1 * y2 - x2 * y1 );
    }
    // res is the determinant of these points
    return fabs(res)*0.5 ;
}
// calculate area of polygoan/convex
