#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d

int main(){
    int n; cin >> n;
    vector<int> a(n-1), b(n-1), c(n);
    rep(i, 0, n-1) cin >> a[i] >> b[i];
    rep(i, 0, n) cin >> c[i];

    sort(c.begin(), c.end(), greater<int>());
    vector<int> ans(n, -1);
    ans[a[0]-1] = c[0];
    ans[b[0]-1] = c[1];
    ll score = c[1];
    rep(i, 2, n){
        rep(j, 0, n-1){
            if(ans[a[j]-1] == -1 and ans[b[j]-1] != -1){
                ans[a[j]-1] = c[i];
                break;
            }else if(ans[a[j]-1] != -1 and ans[b[j]-1] == -1){
                ans[b[j]-1] = c[i];
                break;
            }
        }
        score += c[i];
    }

    cout << score << endl;
    rep(i, 0, n){
        cout << ans[i] <<' ';
    }
    cout << endl;


    
    return 0;
}