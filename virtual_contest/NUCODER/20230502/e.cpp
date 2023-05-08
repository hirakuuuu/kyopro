#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<int> rsp(3);
    rep(i, 0, 3) cin >> rsp[i];
    string s = "rsp";
    string t; cin >> t;
    ll ans = 0;
    vector<int> used(k+1);
    rep(i, 0, n){
        if(i < k){
            rep(j, 0, 3){
                if(t[i] == s[j]){
                    ans += rsp[(j+2)%3];
                    used[i] = 1;
                }
            }
        }else{
            rep(j, 0, 3){
                if(t[i] == s[j]){
                    if(t[i-k] != t[i] or !used[i%k]){
                        ans += rsp[(j+2)%3];
                        used[i%k] = 1;
                    }else{
                        used[i%k] = 0;
                    }
                }
            }
        }
    }
    cout << ans << endl;


    
    return 0;
}