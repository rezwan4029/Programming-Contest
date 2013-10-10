int turn( point O , point A , point B){ //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}


// find angle of <ABC
// angle find in degree for radiant use x*180/PI
double find_angle(point A, point B, point C) { 
    double x = B.sqrdis(C);
    double y = C.sqrdis(A);
    double z = A.sqrdis(B);
    return acos((z*z + x*x - y*y)/(2*z*x));
}


// project point c onto line through a and b
// assuming a != b
point ProjectPointLine(point a, point b, point c)
{
    return a + (b-a)*(c-a).dot(b-a) / (b-a).dot(b-a);
}

// project point c onto line segment through a and b
point ProjectPointSegment(point a, point b, point c)
{
    double r = (b-a).dot(b-a);
    if (fabs(r) < EPS) return a;
    r = (c-a).dot(b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(point a, point b, point c)
{
    return c.dis( ProjectPointSegment(a, b, c) );
}


// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(point a, point b, point c, point d) {
  return fabs( (b-a).cross(c-d)) < EPS;
}

bool LinesCollinear(point a, point b, point c, point d) {
  return LinesParallel(a, b, c, d)
      && fabs( (a-b).cross( a-c) ) < EPS
      && fabs( (c-d).cross(c-a) ) < EPS;
}


// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
// **use LinesParallel and LinesColliner to detect wether they intersect
point ComputeLineIntersection(point a, point b, point c, point d)
{
    b = b - a ;
    d = c - d ;
    c = c - a ;
    assert( b.dot(b) > EPS && d.dot(d) > EPS);
    return a + b* c.cross(d) / b.cross(d) ;
}

// compute center of circle given three points
point ComputeCircleCenter(point a, point b, point c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+(a-b).rotright(), c, c+(a-c).rotright());
}


// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<point> CircleLineIntersection(point a, point b, point c, double r) {
   vector<point> ret;
  b = b-a;
  a = a-c;
  double A = b.dot(b) , B = a.dot(b) , C = a.dot(a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<point> CircleCircleIntersection(point a, point b, double r, double R) {
  vector<point> ret;
  double d = a.dis(b);
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  point v = (b-a)/d;
  ret.push_back(a+v*x + (v.rotleft())*y);
  if (y > 0)
    ret.push_back(a+v*x -(v.rotleft())*y);
  return ret;
}
