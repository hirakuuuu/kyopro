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
// https://atcoder.jp/contests/arc153/tasks/arc153_a

int main(){
    ll n; cin >> n;
    vector<ll> ans;
    vector<ll> o(10);
    o[8] = 1;
    rep(i, 1, 9){
        o[8-i] = o[9-i]*10;
    }

    rep(i, 1, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                rep(ii, 0, 10){
                    rep(jj, 0, 10){
                        rep(kk, 0, 10){
                            ll tmp = 0;
                            rep(l, 0, 9){
                                if(l <= 1) tmp += i*o[l];
                                else if(l == 2) tmp += j*o[l];
                                else if(l == 3) tmp += k*o[l];
                                else if(l <= 5) tmp += ii*o[l];
                                else if(l == 6 or l == 8) tmp += jj*o[l];
                                else tmp += kk*o[l];
                            }
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    cout << ans[n-1] << endl;

    
    return 0;
}