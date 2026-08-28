#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


namespace geometry {
    using D = long double;
    using Point = std::complex<D>;
    const D EPS = 2e-9;
    const D PI = M_PI;

    // 入出力ストリーム
    istream &operator>>(istream &is, Point &p) {
        D a, b;
        is >> a >> b;
        p = Point(a, b);
        return is;
    }
    ostream &operator<<(ostream &os, Point &p) {
        return os << fixed << setprecision(20) << p.real() << " " << p.imag();
    }
    D clean(D x) {
        if (fabsl(x) < 1e-12) return 0;
        return x;
    }
    // d 倍する
    Point add(Point a, Point b) {
    return Point(a.real() + b.real(), a.imag() + b.imag());
    }

    // 偏角（0 <= Θ < 2π）
    D argument(Point p) {
        D res = arg(p);
        if(res < 0.0) res += 2.0*PI; // [-π, π] -> [0, 2π)
        return res;
    }

    // d 倍する
    Point operator*(Point p, D d) {
    return Point(p.real() * d, p.imag() * d);
    }
    Point operator/(Point p, D d) {
    return Point(p.real() / d, p.imag() / d);
    }
    // 等しいかどうか（誤差で判定）
    inline bool equal(D a, D b) { return fabs(a - b) < EPS; }

    // 単位ベクトル
    Point unit_vector(Point a) { return a / abs(a); };

    // 法線ベクトル (逆向きがよければ (0, -1) をかける)
    Point normal_vector(Point a, D dir=1) { return a * Point(0, dir); }

    // 内積：a・b = |a||b|cosΘ
    D dot(Point a, Point b){
        return (a.real() * b.real() + a.imag() * b.imag());
    }

    // 外積：a×b = |a||b|sinΘ (外積の大きさではないか？)
    D cross(Point a, Point b){
        return (a.real() * b.imag() - a.imag() * b.real());
    }

    // 反時計回りに theta 回転
    Point rotate(Point a, D theta) {
        D c = cos(theta), s = sin(theta);
        return Point(c * a.real() - s * a.imag(), s * a.real() + c * a.imag());
    }

    // 直線 
    struct Line {
        Point a, b;
        Line() = default;
        Line(Point a_, Point b_) : a(a_), b(b_) { assert(a_ != b_); };
        // Ax+By=C
        Line(D A, D B, D C){
            if(equal(A, 0)){
                a = Point(0, C/B), b = Point(1, C/B);
            }else if(equal(B, 0)){
                b = Point(C/A, 0), a = Point(C/A, 1);
            }else{
                a = Point(0, C/B), b = Point(C/A, 0);
            }
        }
    };

    // 線分（Line と同じ）
    struct Segment : Line {
        Segment() = default;
        Segment(Point a_, Point b_) : Line(a_, b_) {};
    };

    // 円（中心と半径）
    struct Circle {
        Point p;
        D r;
        Circle() = default;
        Circle(Point p_, D r_) : p(p_), r(r_) {}
    };

    // 射影：直線（線分）に 点p から引いた垂線の足を求める
    Point projection(Line l, Point p){
        D t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }
    Point projection(Segment l, Point p){
        D t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }

    // 反射：直線を対象軸として 点p と線対称の位置にある点を求める
    Point reflection(Line l, Point p){
        return p + (projection(l, p)-p) * 2.0;
    }

    // 3点 a, b, c の位置関係
    // reference: https://sen-comp.hatenablog.com/entry/2020/03/12/145742#iSP3%E7%82%B9%E3%81%AE%E4%BD%8D%E7%BD%AE%E9%96%A2%E4%BF%82
    int ccw(Point a, Point b, Point c){
        b -= a, c -= a;
        // 点 a, b, c が
        if(cross(b, c) >  EPS) return  1; // 反時計回りのとき
        if(cross(b, c) < -EPS) return -1; // 時計回りのとき
        
        // 同一直線上にある場合
        if(dot(b, c) < 0) return 2;      // c, a, b の順
        if(norm(b) < norm(c)) return -2; // a, b, c の順
        return 0;                        // a, c, b の順
    }
    
    // 垂直（内積 == 0）
    bool is_vertical(Line a, Line b){
        return equal(dot(a.b - a.a, b.b - b.a), 0);
    }

    // 平行（外積 == 0）
    bool is_parallel(Line a, Line b){
        return equal(cross(a.b - a.a, b.b - b.a), 0);
    }

    // 線分の交差判定（線分 s に対して, 線分 t の端点が反対側にあればよい）
    bool is_intersect(Segment s, Segment t){
        return (ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0) && 
               (ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0);
    }

    // 線分と円の交差判定
    int is_intersect(const Circle &c, const Segment &l) {
        if(norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
        auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
        if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
        if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
        const Point h = projection(l, c.p);
        if(dot(l.a - h, l.b - h) < 0) return 2;
        return 0;
    }

    // 交点（交差する前提）
    Point cross_point(Line s, Line t){
        D d1 = cross(s.b - s.a, t.b - t.a);
        D d2 = cross(s.b - s.a, s.b - t.a);
        // s, t が一致する場合（適当な１点を返す）
        if(equal(abs(d1), 0) && equal(abs(d2), 0)) return t.a; 
        
        return t.a + (t.b - t.a) * (d2/d1);
    }
    Point cross_point(Segment s, Segment t) {
        assert(is_intersect(s, t)); // 交差する前提
        return cross_point(Line(s), Line(t));
    }

    // 直線と線分の距離
    D dist_line_point(const Line &l, const Point &p) {
        return abs(p - projection(l, p));
    }

    // 線分と点の距離（点p から線分のどこかへの最短距離）
    D dist_segment_point(Segment l, Point p){
        if(dot(l.b - l.a, p - l.a) < EPS) return abs(p - l.a);
        if(dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);
        return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
    }
    // 線分と線分の距離
    D dist_segment_segment(Segment s, Segment t){
        if(is_intersect(s, t)) return 0.0;
        D res = min({
            dist_segment_point(s, t.a),
            dist_segment_point(s, t.b),
            dist_segment_point(t, s.a),
            dist_segment_point(t, s.b),
        });
        return res;
    }

    // Todo : 円, 多角形

    pair<Point, Point> cross_point(const Circle &c, const Line l) {
        Point pr = projection(l, c.p);
        Point e = (l.b - l.a) / abs(l.b - l.a);
        D x = c.r * c.r - norm(pr - c.p);
        if(x < 0 && x > -EPS) x = 0;
        if(x < 0) return {pr, pr};
        D base = sqrt(x);
        return {pr - e * base, pr + e * base};
    }
    pair< Point, Point > cross_point(const Circle &c, const Segment &l) {
        Line aa = Line(l.a, l.b);
        if(is_intersect(c, l) == 2) return cross_point(c, aa);
        auto ret = cross_point(c, aa);
        if(dot(l.a - ret.first, l.b - ret.first) < 0) ret.second = ret.first;
        else ret.first = ret.second;
        return ret;
    }
    // ２つの円の交点
    pair<Point, Point> cross_point(const Circle &c1, const Circle &c2) {
        D d = abs(c1.p - c2.p);
        D cs = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
        cs = max((D)-1, min((D)1, cs));
        D a = acos(cs);
        D t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
        Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
        Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
        return {p1, p2};
    }

    // ２つの円の共通接線（最大４本）
    // 直線と c1 との接点のペアを格納
    vector<Line> tangent(Circle c1, Circle c2) {
        vector<Line> ret;
        if(c1.r < c2.r) swap(c1, c2);
        D g = norm(c1.p - c2.p);
        if(equal(g, 0)) return ret;

        Point u = (c2.p - c1.p) / sqrt(g);
        Point v = rotate(u, PI * 0.5);

        for(int s : {-1, 1}) {
            D h = (c1.r + s * c2.r) / sqrt(g);
            D z = 1 - h * h;
            if(z < 0 && z > -EPS) z = 0;

            if(z == 0) {
                ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
            } else if(z > 0) {
                Point uu = u * h, vv = v * sqrt(z);
                ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
                ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
            }
        }
        return ret;
    }
};
using namespace geometry;


int main(){
    ld x1, y1, r1; cin >> x1 >> y1 >> r1;
    ld x2, y2, r2; cin >> x2 >> y2 >> r2;

    Circle c1(Point(x1, y1), r1);
    Circle c2(Point(x2, y2), r2);

    vector<Line> res = tangent(c1, c2);
    vector<pair<D, D>> ans;
    for(auto l: res){
        pair<Point, Point> p = cross_point(c1, l);
        ans.push_back({clean(p.first.real()), clean(p.first.imag())});
    }
    sort(ans.begin(), ans.end(), [](pair<D, D> a, pair<D, D> b){
        if(equal(a.first, b.first)) return a.second < b.second;
        return a.first < b.first;
    });
    for(auto aa: ans){
        cout << fixed << setprecision(10) << aa.first << ' ' << aa.second << endl;
    }

    return 0;
}