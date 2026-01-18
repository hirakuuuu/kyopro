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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(j, 0, n) cin >> b[j];

        if(n == 1){
            if(a[0]*b[0] < 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            // a[i]/b[i] の値を既約分数として持つ
            vector<int> id(n);
            iota(id.begin(), id.end(), 0);
            sort(id.begin(), id.end(), [&](int i, int j){
                return a[i]*b[j] < a[j]*b[i];
            });

            int i1 = id[0], i2 = id[n-1];
            if(a[i1]*b[i2] == a[i2]*b[i1]){

            }else if(i2 != -1){
                cout << "Yes" << endl;
                vector<int> x(n);
                cout << (a[i1]*b[i2]-a[i2]*b[i1]) << endl;
                x[i1] = (b[i2]+a[i2])/(a[i1]*b[i2]-a[i2]*b[i1])+1;
                x[i2] = (1-a[i1]*x[i1])/a[i2]+1;

                rep(i, 0, n){
                    cout << x[i] << ' ';
                }
                cout << endl;

                ll sum_a = 0, sum_b = 0;
                rep(i, 0, n){
                    sum_a += a[i]*x[i];
                    sum_b += b[i]*x[i];
                }
                assert(sum_a > 0 && sum_b < 0);
            }else{
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}