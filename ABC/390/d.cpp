#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<ll> s;
    vector<ll> t;
    auto f = [&](auto self, int pos) -> void {
        if(pos == n){
            ll tmp = 0;
            rep(i, 0, (int)s.size()){
                tmp ^= s[i];
            }
            t.push_back(tmp);
            return;
        }

        rep(i, 0, (int)s.size()){
            s[i] += a[pos];
            self(self, pos+1);
            s[i] -= a[pos];
        }
        s.push_back(a[pos]);
        self(self, pos+1);
        s.pop_back();
        return;
    };
    f(f, 0);

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    cout << t.size() << endl;
    return 0;
}