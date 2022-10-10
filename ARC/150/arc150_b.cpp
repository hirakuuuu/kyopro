#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc150/tasks/arc150_b

int main(){
    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        ll ans = 0;
        if(a > b){
            ans = a-b;
        }else if(b > a){
            ans = a-b%a;
            vector<int> yakusu;
            for(int i = 1; i*i <= b; i++){
                if(b%i == 0){
                    yakusu.push_back(i);
                    if(b/i != i) yakusu.push_back(b/i);
                }

                for(auto y: yakusu){
                    int bunbo = (b+y-1)/y;
                    if(bunbo <= a) continue;
                    ans = min(ans, (bunbo-a)+(bunbo-b%bunbo));
                }
            }
        }
        cout << ans << endl;


    }
    
    return 0;
}