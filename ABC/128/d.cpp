#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc128/tasks/abc128_d

vector<int> v(55), s(55);

int main(){
    int n, k; cin >> n >> k;
    rep(i, 1, n+1) cin >> v[i];
    

    int rest = max(0, n-k);
    int ans = 0;
    while(rest <= n){
        rep(i, 1, n+2-rest){
            priority_queue<int, vector<int>, greater<int>> que;
            int score = 0;
            rep(j, 1, n+1){
                if(j < i or i+rest-1 < j){
                    if(v[j] < 0){
                        que.push(v[j]);
                    }
                    score += v[j];
                }
            }
            int rest_turn = k-(n-rest);
            while(rest_turn and !que.empty()){
                int q = que.top(); que.pop();
                score -= q;
                rest_turn--;
            }
            ans = max(ans, score);
        }
        rest++;
    }
    cout << ans << endl;

    
    return 0;
}