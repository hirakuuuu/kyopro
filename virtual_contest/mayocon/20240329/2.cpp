#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
    }

    auto is_on_line = [&](int i, int j, int k) -> bool {
        int x1 = x[i]-x[k], y1 = y[i]-y[k];
        int x2 = x[j]-x[k], y2 = y[j]-y[k];
        return x1*y2-y1*x2 == 0;
    };

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, j+1, n){
                if(is_on_line(i, j, k)){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}