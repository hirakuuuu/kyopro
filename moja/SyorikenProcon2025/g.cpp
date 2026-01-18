
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

int main(){
    int h, w; cin >> h >> w;
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    int ans = 0;
    vector<int> l, r;
    rep(i, 0, n){
        cin >> a[i];
        if(cnt[a[i]] == w){
            r.push_back(i);
        }else{
            ans++;
            cnt[a[i]]++;
            l.push_back(i);
        }
    }
    sort(l.begin(), l.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    cout << ans << endl;
    rep(i, 0, l.size()){
        cout << l[i]+1 << ' ';
        if(i%w == w-1) cout << endl;
    }
    rep(i, l.size(), l.size()+r.size()){
        cout << r[i-(int)l.size()]+1 << ' ';
        if(i%w == w-1) cout << endl;
    }
    rep(i, l.size()+r.size(), h*w){
        cout << -1 << ' ';
        if(i%w == w-1) cout << endl;
    }

    return 0;
}