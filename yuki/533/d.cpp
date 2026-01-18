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
    vector<int> l(n), r(n);
    rep(i, 0, n){
        cin >> l[i] >> r[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int cnt = 0;
    do{
        int tmp = 0;
        bool ok = true;
        rep(i, 0, n){
            if(r[p[i]] < tmp){
                ok = false;
                break;
            }
            tmp = min(r[p[i]], max(l[p[i]], tmp));
        }
        if(ok) cnt++;
    }while(next_permutation(p.begin(), p.end()));
    cout << cnt << endl;
    return 0;
}