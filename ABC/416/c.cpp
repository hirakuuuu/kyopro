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
    int n, k, x; cin >> n >> k >> x; x--;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
    }

    vector<string> S;
    vector<int> a;
    auto f = [&](auto self) -> void {
        if(a.size() == k){
            string tmp;
            rep(i, 0, k) tmp += s[a[i]];
            S.push_back(tmp);
            return;
        }
        rep(i, 0, n){
            a.push_back(i);
            self(self);
            a.pop_back();
        }
    };
    f(f);

    sort(S.begin(), S.end());
    cout << S[x] << endl;
    return 0;
}