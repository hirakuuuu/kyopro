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

// 問題
// https://atcoder.jp/contests/arc157/tasks/arc157_b

/*
xの数がｋ以下なら、xを全部ｙにする方針で良い
このとき、できるだけ、隙間を埋めるようにする
ｙをｘに変換するときは、できるだけ、連続したところを選ぶ
*/

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t;
    rep(i, 0, n){
        if(s[i] == 'X') t += 'Y';
        else t += 'X';
    }

    int cnt_x = 0;
    rep(i, 0, n){
        cnt_x += (s[i]=='X');

    }
    if(cnt_x == n){
        cout << max(0, k-1) << endl;
        return 0;
    }
    if(cnt_x == 0){
        cout << max(0, n-1-k) << endl;
        return 0;
    }
    if(cnt_x < k){
        swap(s, t);
        k = n-k;
    }

    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> pos_y;
    rep(i, 0, n){
        if(s[i] == 'Y'){
            pos_y.push_back(i);
        }
    }
    rep(i, 0, pos_y.size()-1){
        if(pos_y[i+1]-pos_y[i]-1 > 0) que.push(pos_y[i+1]-pos_y[i]-1);
        else ans++;
    }

    while(k > 0 && !que.empty()){
        int q = que.top(); que.pop();
        if(k >= q){
            ans += q+1;
            k -= q;
        }else{
            ans += k;
            k = 0;
        }
    }

    cout << ans+k << endl;

    
    return 0;
}