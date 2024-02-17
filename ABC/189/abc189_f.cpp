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
// https://atcoder.jp/contests/abc189/tasks/abc189_f


int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(k);
    vector<bool> b(n+1);
    rep(i, 0, k){
        cin >> a[i];
        b[a[i]] = true;
    }
    // 到達できるかどうかを検証
    queue<int> que;
    que.push(0);
    int l = 1;
    while(!que.empty()){
        int q = que.front(); que.pop();
        rep(i, l, min(n+1, q+m)+1){
            if(b[i]) continue;
            que.push(i);
            l = i+1;
        }

    }
    if(l != n+2){
        cout << -1 << endl;
        return 0;
    }

    // 到達できる場合
    vector<double> dp_a(n+m+1, 0.0), dp_b(n+m+1, 0.0);
    vector<double> acc_a(n+m+2, 0.0), acc_b(n+m+2, 0.0);
    rrep(i, n-1, 0){
        if(b[i]){
            dp_a[i] = 1.0, dp_b[i] = 0.0;
        }else{
            dp_a[i] = (double)acc_a[i+1]/m;
            dp_b[i] = (double)acc_b[i+1]/m+1.0;
        }
        acc_a[i] = acc_a[i+1]+dp_a[i]-dp_a[i+m];
        acc_b[i] = acc_b[i+1]+dp_b[i]-dp_b[i+m];
    }
    printf("%.10f\n", dp_b[0]/(1-dp_a[0]));







    return 0;
}