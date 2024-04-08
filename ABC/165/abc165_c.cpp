#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    rep(i, 0, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> A = {1};
    auto f = [&](auto self, int i) -> int {
        if(i == n){
            int res = 0;
            rep(j, 0, q){
                if(A[b[j]]-A[a[j]] == c[j]) res += d[j];
            }
            return res;
        }
        int res = 0;
        rep(j, A.back(), m+1){
            A.push_back(j);
            chmax(res, self(self, i+1));
            A.pop_back();
        }
        return res;
    };
    cout << f(f, 0) << endl;

    
    return 0;
}