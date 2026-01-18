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
    int n, q; cin >> n >> q;
    vector<int> b(q);
    vector<pair<int, int>> cnt(n);
    rep(i, 0, n) cnt[i].second = i+1;
    rep(i, 0, q){
        int x; cin >> x;
        if(x == 0){
            sort(cnt.begin(), cnt.end());
            b[i] = cnt[0].second;
            cnt[0].first++;
        }else{
            b[i] = x;
            rep(j, 0, n){
                if(cnt[j].second == x) cnt[j].first++;
            }
        }
    }

    rep(i, 0, q){
        cout << b[i] << ' ';
    }
    cout << endl;
    
    return 0;
}