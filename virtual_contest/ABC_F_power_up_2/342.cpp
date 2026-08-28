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
    int n, l, d; cin >> n >> l >> d;

    vector<ld> prob_d(n+d+1);
    prob_d[1] = 1.0/d;
    prob_d[d+1] = -1.0/d;
    rep(i, 1, l){
        prob_d[i+1] += prob_d[i]/d;
        prob_d[i+d+1] -= prob_d[i]/d;
        prob_d[i+1] += prob_d[i];
    }
    rep(i, l, n+d) prob_d[i+1] += prob_d[i];


    vector<ld> acc_prob_d(n+d+1);
    acc_prob_d[n+d] = prob_d[n+d];
    rrep(i, n+d-1, 0) acc_prob_d[i] = acc_prob_d[i+1]+prob_d[i];


    vector<ld> prob_m(n+d+1);
    prob_m[n] = 1.0-prob_d[n];
    ld acc_prob_m = prob_m[n]/d;
    rrep(i, n-1, 0){
        ld p1 = max((ld)0.0, acc_prob_d[l]-acc_prob_d[i])+(acc_prob_d[n+1]);
        ld p2 = acc_prob_m;
        prob_m[i] = max(p1, p2);
        
        acc_prob_m += prob_m[i]/d;
        acc_prob_m -= prob_m[i+d]/d;
    }
    cout << setprecision(20) << prob_m[0] << endl;


    
    return 0;
}