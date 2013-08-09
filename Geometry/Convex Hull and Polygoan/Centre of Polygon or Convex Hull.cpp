point centre_poly(vector< point > P){ 
    double area = poly_area(P);
    double factor = 1.0 / (6 * area);
    double cx = 0, cy = 0;
    int i,sz = P.size();
    for( i = 0 ; i < sz ; i++)
    {
        point cur = P[i] , next = P[(i + 1) % sz];
        cx += (cur.x + next.x) * (cur.x * next.y - cur.y * next.x);
        cy += (cur.y + next.y) * (cur.x * next.y - cur.y * next.x);
    }
    cx *= factor;
    cy *= factor;
    return point(cx, cy);
}