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

// 偏角ソート
struct Point {
    ll x, y;
    Point(ll _x=0, ll _y=0): x(_x), y(_y) {};
};
ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
bool cmp(const Point &a, const Point &b) {
    ll ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    ll bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}
void argument_sort(vector<Point> &points) {
    sort(points.begin(), points.end(), cmp);
}

int main(){
    int n, q; cin >> n >> q;
    vector<Point> v(n);
    rep(i, 0, n){
        ll x, y; cin >> x >> y;
        v[i] = Point(x, y);
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](const int a, const int b){
        return cmp(v[a], v[b]);
    });

    vector<int> l(n), r(n);
    rep(i, 1, n){
        if(!cmp(v[ind[i-1]], v[ind[i]])) l[i] = l[i-1];
        else l[i] = i;
    }
    r[n-1] = n-1;
    rrep(i, n-2, 0){
        if(!cmp(v[ind[i]], v[ind[i+1]])) r[i] = r[i+1];
        else r[i] = i;
    }

    vector<int> rev(n);
    rep(i, 0, n) rev[ind[i]] = i;

    while(q--){
        int a, b; cin >> a >> b; a--, b--;
        if(r[rev[a]] >= l[rev[b]]){
            cout << r[rev[a]]-l[rev[b]]+1 << endl;
        }else{
            cout << n-(l[rev[b]]-r[rev[a]]-1) << endl;
        }
    }
    
    return 0;
}