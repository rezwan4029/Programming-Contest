const double R = 6378.00 ; // radius of earth / sphere

// great Circle in Sphere / points must be in radian / distance between 2 pnts on earth
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {
       double dlon = lon2 - lon1;
       double dlat = lat2 - lat1;
       double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       return d+EPS;
}
