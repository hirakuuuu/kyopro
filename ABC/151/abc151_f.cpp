#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
// constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc151/tasks/abc151_f

const double EPS = 0.0001;
const double INF = 1000000;

// 座標の構造体
struct point{
  double x, y;
  point(){
  }
  point(double x_, double y_): x(x_), y(y_){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator *(double k){
    return point(x * k, y * k);
  }
  point operator /(double k){
    return point(x / k, y / k);
  }
};

// 90度回転
point rotate90(point P){
  return point(P.y, -P.x);
}

// 中点
point midpoint(point P, point Q){
  return (P + Q) / 2;
}

// 絶対値
double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}

// 距離
double dist(point P, point Q){
  return abs(Q - P);
}

// 内積
double dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}

// 外積
double cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}

// 同一直線上にあるかどうか
double is_collinear(point P, point Q, point R){
  return abs(cross(Q - P, R - P)) < EPS;
}

// 直線の構造体
struct line{
  point A, B;
  line(point A_, point B_): A(A_), B(B_){
  }
};

// 直線の方向ベクトル
point vec(line L){
  return L.B - L.A;
}

// 垂直二等分線
line perpendicular_bisector(point P, point Q){
  point A = midpoint(P, Q);
  point B = A + rotate90(Q - P);
  return line(A, B);
}

// 直線の交点
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}

// 外心
point circumcenter(point A, point B, point C){
  return line_intersection(perpendicular_bisector(A, B), perpendicular_bisector(A, C));
}


int main(){
    int n; cin >> n;
    vector<point> p(100);
    rep(i, 0, n) cin >> p[i].x >> p[i].y;
    vector<point> c;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            c.push_back(midpoint(p[i], p[j]));
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (!is_collinear(p[i], p[j], p[k])){
                    c.push_back(circumcenter(p[i], p[j], p[k]));
                }
            }
        }
    }
    double ans = INF;
    for (point q: c){
        double mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dist(q, p[i]));
        }
        ans = min(ans, mx);
    }
    printf("%.20f\n", ans);
    return 0;
}