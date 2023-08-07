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
// https://atcoder.jp/contests/abc127/tasks/abc127_f

int main(){
    int q; cin >> q;
    ll b_sum = 0;
    ll f_sum = 0, l_sum = 0;
    priority_queue<ll> fque;
    priority_queue<ll, vector<ll>, greater<ll>> lque;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll a, b; cin >> a >> b;
            b_sum += b;
            if((fque.size()+lque.size())%2 == 0){
                if(!lque.empty()){
                    if(a <= lque.top()){
                        fque.push(a);
                        f_sum += a;
                    }else{
                        ll tmp = lque.top(); lque.pop();
                        lque.push(a);
                        fque.push(tmp);
                        f_sum += tmp;
                        l_sum += a-tmp;
                    }
                }else{
                    fque.push(a);
                    f_sum += a;
                }
            }else{
                if(fque.top() <= a){
                    lque.push(a);
                    l_sum += a;
                }else{
                    ll tmp = fque.top(); fque.pop();
                    fque.push(a);
                    lque.push(tmp);
                    f_sum += a-tmp;
                    l_sum += tmp;
                }
            }
        }else{
            ll x = fque.top();
            ll ans = (x*fque.size()-f_sum)+(l_sum-x*lque.size())+b_sum;
            cout << x << ' ' << ans << endl;
        }
    }
    return 0;
}