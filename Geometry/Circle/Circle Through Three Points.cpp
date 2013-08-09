bool CircleThroughThreePoints(point p1, point p2, point p3, point &center, double &r){ 
  double a,b,c,d,e,f,g;
  a = p2.x - p1.x ;  b = p2.y - p1.y ;
  c = p3.x - p1.x ;  d = p3.y - p1.y ;
  e = a*(p1.x + p2.x) + b*(p1.y + p2.y) ;
  f = c*(p1.x + p3.x) + d*(p1.y + p3.y) ;
  g = 2.0 * ( a*(p3.y - p2.y) - b*( p3.x - p2.x ) );
  if (fabs(g) < EPS) return false;
  center = point ( (d*e - b*f) / g , (a*f - c*e) / g ) ;
  r = sqrt( sqr( p1.x - center.x ) + sqr( p1.y - center.y ) );
  return true;
}
// retuns true if circle can be made or false if points are in colinear
