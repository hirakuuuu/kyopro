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

// 座標の構造体
struct Point{
    ll x, y;
    Point(){
    }
    Point(ll x_, ll y_): x(x_), y(y_){
    }
    Point operator +(Point P){
        return Point(x + P.x, y + P.y);
    }
    Point operator -(Point P){
        return Point(x - P.x, y - P.y);
    }
    bool operator<(Point P) {
        if (x < P.x) return true;
        if (x > P.x) return false;
        if (y < P.y) return true;
        return false;
    }
};

// 90度回転
Point rotate90(Point P){
  return Point(P.y, -P.x);
}

// 内積
ll dot(Point P, Point Q){
  return P.x * Q.x + P.y * Q.y;
}

// 外積
ll cross(Point P, Point Q){
  return P.x * Q.y - P.y * Q.x;
}


int main(){   
    int n; cin >> n;
    vector<Point> g(n);
    rep(i, 0, n) cin >> g[i].x >> g[i].y;
    sort(g.begin(), g.end());

    // 凸包を求める
    // 上側凸包と下側凸包を同時に求める
    vector<Point> g1, g2, convex;
    g1.push_back(g[0]), g2.push_back(g[0]);
    g1.push_back(g[1]), g2.push_back(g[1]);
    rep(i, 2, n){
        // x座標が小さい順に p1, p2, p3 とする. p1p2, p3p2 の外積が負なら反時計回り
        // このとき、p2 は凸包に含まれない 
        while(g1.size() >= 2 && cross(g1[g1.size()-2]-g1[g1.size()-1], g[i]-g1[g1.size()-1]) <= 0){
            g1.pop_back();
        }
        // x座標が小さい順に p1, p2, p3 とする. p1p2, p3p2 の外積が正なら時計回り
        // このとき、p2 は凸包に含まれない 
        while(g2.size() >= 2 && cross(g2[g2.size()-2]-g2[g2.size()-1], g[i]-g2[g2.size()-1]) >= 0){
            g2.pop_back();
        }
        g1.push_back(g[i]);
        g2.push_back(g[i]);
    }
    // 上側から時計回りに追加
    rep(i, 0, g1.size()) convex.push_back(g1[i]);
    rrep(i, g2.size()-2, 1) convex.push_back(g2[i]);

    if(convex.size() == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}