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
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> r(n);
    rep(i, 0, n){
        cin >> r[i];
    }
    {
        rep(_, 0, 2){
            while(s.back() == '#'){
                s.pop_back();
                r.pop_back();
            }
            reverse(s.begin(), s.end());
            reverse(r.begin(), r.end());
        }
        n = (int)s.size();
    }

    vector<pair<ll, ll>> rle;
    for(int i = 0; i < n; ){
        int j = i;
        rle.emplace_back(0, 0);
        while(j < n && s[i] == s[j]){
            if(rle.back().first < r[j]){
                rle.back().first = r[j];
                rle.back().second = 1;
            }else if(rle.back().first == r[j]){
                rle.back().second++;
            }
            j++;
        }
        i = j;
    }

    ll mx = 0;
    for(auto [v, cnt]: rle) chmax(mx, v);
    int m = (int)rle.size();
    
    ll ans = 0;
    rep(i, 0, m){
        if(rle[i].first == mx){
            if(i%2 == 0){
                if(i > 0) ans += rle[i].second*rle[i-2].second;
                if(i < m-1 && rle[i+2].first != mx) ans += rle[i].second*rle[i+2].second;
            }else{
                if(rle[i-1].first != mx && rle[i+1].first != mx) ans += rle[i-1].second*rle[i+1].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}