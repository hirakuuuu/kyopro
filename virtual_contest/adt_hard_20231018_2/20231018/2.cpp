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
    vector<double> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    double sum = 0.0;
    rep(i, 0, n) sum += a[i]/b[i];
    double half = sum/2.0;

    int ind = 0;
    double tmp = 0.0;
    double ans = half;
    while(ans > 0.0){
        if(ans-a[ind]/b[ind] > 0.0){
            ans -= a[ind]/b[ind];
            tmp += a[ind];
            ind++;
        }else{
            tmp += ans*b[ind];
            ind++;
            break;
        }
    }

    printf("%.10f\n", tmp);


    return 0;
}