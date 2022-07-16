#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tasks/arc144_c

int main(){
    ll n, k; cin >> n >> k;

    queue<ll> que_M, que_m;
    vector<ll> ans(n);
    ll id = 1;

    rep(i, 1, n+1){
        if(i <= k){
            que_m.push(i);
        }else if(2*k < i){
            que_M.push(i);
        }else{
            ans[i-k-1] = i;
            id++;
        }
    }
    while(id <= n){
        if(!que_m.empty() and !que_M.empty()){
            ll qm = que_m.front();
            ll qM = que_M.front();

            if(abs(qM-id-1) >= k){
                ans[id-1] = qm;
                que_m.pop();
            }else if(abs(id-qm+(ll)que_M.size()) >= k){
                ans[id-1] = qM;
                que_M.pop();
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else if(!que_m.empty()){
            ll q = que_m.front(); que_m.pop();
            if(abs(id-q) >= k) ans[id-1] = q;
            else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            ll q = que_M.front(); que_M.pop();
            if(abs(id-q) >= k) ans[id-1] = q;
            else{
                cout << -1 << endl;
                return 0;
            }
        }
        id++;
    }

    rep(i, 0, n){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}