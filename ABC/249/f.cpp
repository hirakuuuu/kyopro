#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc249/tasks/abc249_f

int main(){
    int n, k; cin >> n >> k;
    vector<ll> t(n+1), y(n+1);
    t[0] = 1, y[0] = 0;
    rep(i, 1, n+1) cin >> t[i] >> y[i];
    reverse(t.begin(), t.end());
    reverse(y.begin(), y.end());

    priority_queue<ll> que;
    ll sum = 0, ans = -(1LL<<60);
    rep(i, 0, n+1){
        if(t[i] == 1){
            ans = max(ans, y[i]+sum);
            if(k > 0 and que.size() == k){
                sum += que.top(); que.pop();
            }
            k--;
            if(k < 0) break;
        }else{
            if(k > 0 and que.size() == k){
                ll q = que.top();
                if(y[i] < q){
                    que.pop();
                    que.push(y[i]);
                    sum += q;
                }else sum += y[i];
            }else{
                if(que.size() < k and y[i] < 0) que.push(y[i]);
                else sum += y[i];
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}