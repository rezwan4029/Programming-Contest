int EQ(double d){
    if (fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

struct point3D{
    double x , y , z;
    point3D(){}
    point3D(double _x , double _y , double _z){
        x = _x , y = _y , z = _z;
    }
    bool operator==(point3D a)
    {
        return EQ(a.x-x) == 0 && EQ(a.y-y) == 0 && EQ(a.z-z) == 0;
    }
    point3D operator-(point3D k){
        return point3D(x - k.x , y - k.y , z - k.z );
    }
    point3D operator+(point3D k){
        return point3D(x + k.x , y + k.y , z + k.z );
    }
    point3D operator*(double k) {
        return point3D(x * k , y * k , z * k );
    }
    double len(){
        return sqrt( x * x + y * y + z * z ) ;
    }
    double dot(point3D p){
        return x*p.x + y*p.y + z*p.z ;
    }
    point3D cross(point3D p){
        return point3D( y*p.z - p.y*z , p.x*z - x*p.z , x*p.y - p.x*y );
    }
    double dis(point3D p){
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)+(p.z-z)*(p.z-z));
    }
    void normalize(){
        double r = len();
        x /= r , y /= r , z /= r ;
    }
    point3D trunc(double r){
        r /= len();
        return point3D(x*r,y*r,z*r);
    }
    void input(){
        scanf("%lf %lf %lf",&x,&y,&z);
    }
};

struct line3D{
    point3D a,b;
    line3D(){}
    line3D(point3D _a,point3D _b){
        a = _a , b = _b;
    }
    bool operator==(line3D x){
        return (a == x.a )&&( b == x.b );
    }
    void input(){
        a.input();
        b.input();
    }
    double length(){
        return a.dis(b);
    }
    bool pointonseg(point3D p){ // not checked
        EQ( (p-a).cross(p-b).len() ) == 0 && EQ( (a-p).dot(b-p) ) <= 0 ;
    }
    double dispointtoline(point3D p){ // not checked
        return ((b-a).cross(p-a)).len()/ a.dis(b) ;
    }
    point3D lineprog(point3D p){ // not checked
        return a + ( (b-a).trunc( ((b-a)).dot(p-a)  /b.dis(a)));
    }
};

int opposite(point3D p,point3D q,point3D a,point3D b,point3D c){
    point3D v = (b-a).cross(c-a);
    double x = v.dot(p-a) , y = v.dot(q-a);
    return EQ( x * y ) <= 0;
}

//traingle ABC and segment PQ wether intersect
//can use for triangle triangle intersection
bool segCrossTri(point3D p,point3D q,point3D a,point3D b,point3D c){
    return opposite(p,q,a,b,c) && opposite(a,b,p,q,c)
        && opposite(a,c,p,q,b) && opposite(b,c,p,q,a);
}

//distance segment AB to point C
double SegmentToPointDis(point3D a , point3D b , point3D c ){
    if( (b-a).dot(c-a) < 0 ) return (c-a).len();
    if( (a-b).dot(c-b) < 0 ) return (c-b).len();
    point3D C = (b-a).cross(c-a);
    return C.len() / (a-b).len();
}
//rotate the line pr to theta
point3D rotate(point3D p, point3D r, double theta){
   point3D q(0,0,0);
   double costheta = cos(theta) ,sintheta = sin(theta);
   r.normalize();

   q.x += (costheta + (1 - costheta) * r.x * r.x) * p.x;
   q.x += ((1 - costheta) * r.x * r.y - r.z * sintheta) * p.y;
   q.x += ((1 - costheta) * r.x * r.z + r.y * sintheta) * p.z;

   q.y += ((1 - costheta) * r.x * r.y + r.z * sintheta) * p.x;
   q.y += (costheta + (1 - costheta) * r.y * r.y) * p.y;
   q.y += ((1 - costheta) * r.y * r.z - r.x * sintheta) * p.z;

   q.z += ((1 - costheta) * r.x * r.z - r.y * sintheta) * p.x;
   q.z += ((1 - costheta) * r.y * r.z + r.x * sintheta) * p.y;
   q.z += (costheta + (1 - costheta) * r.z * r.z) * p.z;

   return q;
}
