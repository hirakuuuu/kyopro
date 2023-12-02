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
// https://atcoder.jp/contests/arc158/tasks/arc158_b

int main(){
    int n; cin >> n;
    vector<double> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<double> inv_x(n);
    rep(i, 0, n) inv_x[i] = 1.0/x[i];
    sort(inv_x.begin(), inv_x.end());
    
    vector<double> b;
    rep(i, 0, 3) b.push_back(1.0/inv_x[i]);
    rrep(i, n-1, max(3, n-3)) b.push_back(1.0/inv_x[i]);

    vector<int> ind(b.size());
    rep(i, 0, 3){
        ind[b.size()-i-1] = 1;
    }
    double M= -10, m = 10;
    do{
        double l = 0.0, r = 1.0;
        rep(i, 0, b.size()){
            if(ind[i]){
                l += b[i];
                r *= b[i];
            }
        }
        chmax(M, l/r);
        chmin(m, l/r);
    }while(next_permutation(ind.begin(), ind.end()));
    
    printf("%.20f\n", m);
    printf("%.20f\n", M);
    return 0;
}