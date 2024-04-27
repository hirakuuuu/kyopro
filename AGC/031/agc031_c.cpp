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
    int n, a, b; cin >> n >> a >> b;
    if(__popcount(a^b)%2 != 1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    auto f = [&](auto self, int L, int R, int A, int B) -> vector<int> {
        if(R-L == 1){
            return {0};
        }
        int x = -1;
        rep(i, 0, n){
            if((A^B)&(1<<i)){
                x = i;
                break;
            }
        }
        int A_ = (A&((1<<x)-1))+((A&((1<<n)-1-((1<<x+1)-1)))>>1);
        int B_ = (B&((1<<x)-1))+((B&((1<<n)-1-((1<<x+1)-1)))>>1);
        int C = A_^1;
        vector<int> q = self(self, L, L+(R-L)/2, A_, C);
        vector<int> r = self(self, L+(R-L)/2, R, C, B_);
        // cout << L << ' ' << R << ' ' << x << endl;
        // rep(i, 0, (R-L)/2) cout << q[i] << ' ';
        // cout << endl;
        // rep(i, 0, (R-L)/2) cout << r[i] << ' ';
        // cout << endl;
        vector<int> res(R-L);
        rep(i, 0, (R-L)/2){
            res[i] = (q[i]&((1<<x)-1))+((q[i]&((1<<n)-(1<<x)))<<1);
            if(A&(1<<x)) res[i] += (1<<x);
        }
        rep(i, (R-L)/2, (R-L)){
            res[i] = (r[i-(R-L)/2]&((1<<x)-1))+((r[i-(R-L)/2]&((1<<n)-(1<<x)))<<1);
            if(B&(1<<x)) res[i] += (1<<x);
        }
        return res;
    };
    vector<int> p = f(f, 0, 1<<n, a, b);
    rep(i, 0, 1<<n){
        cout << p[i] <<' ';
    }
    cout << endl;


    return 0;
}