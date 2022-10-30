#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// ポイントクラス
#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point {
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x+p.x, y+p.y); }
    Point operator - (Point p) { return Point(x-p.x, y-p.y); }
    Point operator * (double a) { return Point(x*a, y*a); }
    Point operator / (double a) { return Point(x/a, y/a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x*x + y*y; }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};
typedef Point Vector;

// 線分
struct Segment {
    Point p1, p2;
};

// 線分が交わるかどうか
// https://oshiete.goo.ne.jp/qa/672905.html

bool intersect(Segment s, Segment t){
    double a1 = (s.p1.y-s.p2.y)*(t.p1.x-s.p1.x)-(s.p1.x-s.p2.x)*(t.p1.y-s.p1.y);
    double a2 = (s.p1.y-s.p2.y)*(t.p2.x-s.p1.x)-(s.p1.x-s.p2.x)*(t.p2.y-s.p1.y);
    double a3 = (t.p1.y-t.p2.y)*(s.p1.x-t.p1.x)-(t.p1.x-t.p2.x)*(s.p1.y-t.p1.y);
    double a4 = (t.p1.y-t.p2.y)*(s.p2.x-t.p1.x)-(t.p1.x-t.p2.x)*(s.p2.y-t.p1.y);
    if(a1*a2 <= 0 and a3*a4 <= 0) return true;
    return false;
}

// 直線
typedef Segment Line;

// 円
struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

// 多角形
typedef vector<Point> Polygon;

// 内積
double dot(Vector a, Vector b){
    return a.x*b.x+a.y*b.y;
}
// 外積
double cross(Vector a, Vector b){
    return a.x*b.y-a.y*b.x;
}

// 射影
Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p-s.p1, base)/base.norm();
    return s.p1+base*r;
}

// 反射
Point reflect(Segment s, Point p){
    return p+(project(s, p)-p)*2;
}

// 点と直線の距離
double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2-l.p1, p-l.p1)/((l.p2 - l.p1).abs()));
}

// 点と線分の距離
double getDistanceSP(Segment s, Point p){
    if(dot(s.p2-s.p1, p-s.p1) < 0.0) return (p-s.p1).abs();
    if(dot(s.p1-s.p2, p-s.p2) < 0.0) return (p-s.p2).abs();
    return getDistanceLP(s, p);
}

// 線分と線分の距離
double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}



int main(){
    int q; cin >> q;
    vector<double> ans;
    while(q--){
        Segment s1, s2;
        cin >> s1.p1.x >> s1.p1.y >> s1.p2.x >> s1.p2.y;
        cin >> s2.p1.x >> s2.p1.y >> s2.p2.x >> s2.p2.y;
        ans.push_back(getDistance(s1, s2));

    }
    for(auto aa: ans){
        printf("%.10f\n", aa);
    }
}