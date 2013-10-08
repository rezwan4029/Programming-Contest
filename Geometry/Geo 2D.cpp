double dot(point p, point q)     { return p.x*q.x+p.y*q.y; }
double dist2(point p, point q)   { return dot(p-q,p-q); }
double cross(point p, point q)   { return p.x*q.y-p.y*q.x; }

// project point c onto line through a and b
// assuming a != b
point ProjectPointLine(point a, point b, point c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}


// project point c onto line segment through a and b
point ProjectPointSegment(point a, point b, point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(point a, point b, point c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}


// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(point a, point b, point c, point d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(point a, point b, point c, point d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}


// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(point a, point b, point c, point d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
point ComputeLineIntersection(point a, point b, point c, point d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
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
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
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
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  point v = (b-a)/d;
  ret.push_back(a+v*x + (v.rotleft())*y);
  if (y > 0)
    ret.push_back(a+v*x -(v.rotleft())*y);
  return ret;
}
