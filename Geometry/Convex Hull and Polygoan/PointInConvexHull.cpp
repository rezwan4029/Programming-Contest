bool PointInConvexHull( point p ){
        if ( points.size() < 3 ) return false;
        for (int i = 0 ; i < points.size()-1 ; i++ ){
             int j = i + 1;
             int c = cross( points[i], points[j], p );
             int x = min( points[i].x, points[j].x );
             int X = max( points[i].x, points[j].x );
             int y = min( points[i].y, points[j].y );
             int Y = max( points[i].y, points[j].y );

             int d = x <= p.x && p.x <= X && y <= p.y && p.y <= Y ;
             if ( c < 0 )    return false;
             else if ( c == 0 && d == 0 ) return false;
        }
        return true;
}