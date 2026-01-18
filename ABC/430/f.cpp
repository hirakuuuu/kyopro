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
        string s; cin >> s;
        vector<int> pre_l(n+1), pre_r(n+1);
        rep(i, 1, n){
            if(s[i-1] == 'L'){
                pre_l[i] = pre_l[i-1]+1;
            }else{
                pre_r[i] = pre_r[i-1]+1;
            }
            // cout << pre_l[i] << ' ' <<pre_r[i] << endl;
        }
        vector<int> nx_l(n+1), nx_r(n+1);
        rrep(i, n-2, 0){
            if(s[i] == 'L'){
                nx_l[i] = nx_l[i+1]+1;
            }else{
                nx_r[i] = nx_r[i+1]+1;
            }
            // cout << nx_l[i] << ' ' <<nx_r[i] << endl;
        }

        vector<int> ans(n+1);
        rep(i, 0, n){
            int l = pre_r[i]+nx_l[i];
            int r = n-(pre_l[i]+nx_r[i]);
            // cout << i << ' ' << l << ' ' << r << endl;
            ans[l]++;
            ans[r]--;
        }
        rep(i, 0, n) ans[i+1] += ans[i];
        rep(i, 0, n){
            cout << ans[i] << ' ';
        } 
        cout << endl;


    }
    return 0;
}