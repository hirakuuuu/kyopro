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
constexpr ll INF = 9e18;
constexpr double inf = 1e10;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 速度ごとの左端と右端
// 速度は (-1, 0, 1) -> (0, 1, 2) とする（相対的な位置関係は崩れないので）
// また、各速度ごとの右端と左端だけを持っておけば、幅が切り替わるタイミングが全て計算できる
struct D {
    vector<double> l, r;
    D(): l(3, inf), r(3, -inf) {}

    void add(double x, int v) {
        ++v;
        chmin(l[v], x);
        chmax(r[v], x);
    }

    double get(double t){
        double nl = inf, nr = -inf;
        rep(i, 0, 3){
            chmin(nl, l[i]+i*t);
            chmax(nr, r[i]+i*t);
        }
        return nr-nl;
    }

    vector<double> events() {
        vector<double> ts;
        rep(i, 0, 3){
            rep(j, 0, i){ // j < i
                double t = (l[j]-l[i])/(i-j);
                if(t > 0) ts.push_back(t);
            }
        }
        rep(i, 0, 3){
            rep(j, 0, i){ // j < i
                double t = (r[j]-r[i])/(i-j);
                if(t > 0) ts.push_back(t);
            }
        }
        return ts;
    }


};

int main(){
    int n; cin >> n;
    D xd, yd;
    rep(i, 0, n){
        int x, y;
        char d;
        cin >> x >> y >> d;
        if(d == 'L') xd.add(x, -1), yd.add(y, 0);
        if(d == 'R') xd.add(x, 1), yd.add(y, 0);
        if(d == 'U') xd.add(x, 0), yd.add(y, 1);
        if(d == 'D') xd.add(x, 0), yd.add(y, -1);
    }
    
    vector<double> ts;
    ts.push_back(0);
    ts.push_back(inf);
    {
        auto nts = xd.events();
        ts.insert(ts.end(), nts.begin(), nts.end());
    }
    {
        auto nts = yd.events();
        ts.insert(ts.end(), nts.begin(), nts.end());
    }
    sort(ts.begin(), ts.end());
    
    double ans = 1e18;
    for(double t: ts) {
        double now = xd.get(t)*yd.get(t);
        chmin(ans, now);
    }
    cout << setprecision(20) << ans << endl;





    return 0;
}