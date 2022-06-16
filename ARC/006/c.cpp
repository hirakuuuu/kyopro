#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc006/tasks/arc006_3

int main(){
    int n; cin >> n;
    set<int> s;
    rep(i, 0, n){
        int w; cin >> w;
        auto itr = s.lower_bound(w);
        if(itr == s.end()){
            s.insert(w);
        }else{
            s.erase(itr);
            s.insert(w);
        }
    }
    cout << s.size() << endl;
    
    return 0;
}