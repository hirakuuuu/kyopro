#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc271/tasks/abc271_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    map<int, bool> exist;
    rep(i, 0, n){
        cin >> a[i];
        if(exist[a[i]]) cnt++;
        else exist[a[i]] = true;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0, r = a.size()-1, i = 1;


    while(r >= 0){
        if(!exist[i]){
            if(cnt >= 2){
                cnt -= 2;
            }else if(cnt == 1){
                cnt = 0;
                if(r < 0 or a[r] < i) break;
                exist[a[r]] = false;
                r--;
            }else{
                if(r < 0 or a[r] < i) break;
                exist[a[r]] = false;
                r--;
                if(r < 0 or a[r] < i) break;
                exist[a[r]] = false;
                r--;
            }
        }
        ans++;
        exist[i] = true;
        i++;
    }

    cout << ans << endl;
    
    return 0;
}