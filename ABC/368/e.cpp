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

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, m; cin >> n >> m;
    vector<ll> x(m); cin >> x[0];

    vector<int> a(m), b(m);
    vector<ll> s(m), t(m);
    vector<tuple<ll, ll, ll>> event;
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> s[i] >> t[i];
        a[i]--, b[i]--;
        event.push_back({s[i], 1, i});
        event.push_back({t[i], 0, i});
    }
    sort(event.begin(), event.end());
    vector<ll> mx(n);
    for(auto [time, f, ind]: event){
        if(f){
            if(ind == 0) continue;
            // 発車　すでに到着済みの電車で一番遅いものに合わせて発射する
            // これ以降に到着する電車については、そもそも乗り換え不可能なので、考える必要がない
            x[ind] = max(0LL, mx[a[ind]]-time);
        }else{
            // 到着　その時点での駅の到着時刻の最大値を更新
            chmax(mx[b[ind]], time+x[ind]);
        }
    }
    rep(i, 1, m){
        cout << x[i] << ' ';
    }
    cout << endl;
    
    return 0;
}