/*
Return whether a polygon in 2D is concave or convex
   return 0 for incomputables eg: colinear points
   CONVEX = 1
   CONCAVE = -1
*/

int isConvex (vector<point>p) {
   int n = p.size() ;
   if (n < 3 ) return (0);
   int flag = 0;
   for ( int i = 0; i < n; i++ ) {
      int j = (i + 1)% n , k = (i + 2)% n;
      double z = ( p[j].x - p[i].x ) * ( p[k].y - p[j].y );
      z -= ( p[j].y - p[i].y ) * ( p[k].x - p[j].x );
      if (z < 0 ) flag |= 1;
      else if (z > 0 ) flag |= 2;
      if (flag == 3) return -1;
   }
   if (flag != 0 ) return 1 ;
   return 0;
}
