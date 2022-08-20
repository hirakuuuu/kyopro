#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc146/tasks/arc146_b

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }


    ll ans = 0, o = (1<<30);
    while(o){
        ll num = ans+o;
        priority_queue<ll> que;
        ll total = 0LL;
        rep(j, 0, n){
            ll need = 0;
            if((a[j]&num) != num){
                int l = 30;
                while(l >= 0){
                    if((num&(1<<l)) and (a[j]&(1<<l)) == 0){
                        need = (1<<l)-(a[j]&((1<<l)-1))+(num&((1<<l)-1));
                        break;
                    }
                    l--;
                }
            }
            if(j >= k){
                ll q = que.top(); que.pop();
                total -= q;
                need = min(need, q);
            }
            total += need;
            que.push(need);
        }

        if(total <= m){
            ans += o;
        }
        o /= 2;
    }

    cout << ans << endl;

    
    return 0;
}