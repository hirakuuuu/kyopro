#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<int> a(101);

int main(){
    int n; cin >> n;
    int ans = -1;
    vector<int> r(n+1), c(n+1);
    vector<int> cnt(n+1);
    rep(i, 0, n){
        int h, w; cin >> h >> w;
        r[h] = w;
        c[w] = h;
        cnt[h]++, cnt[w]++;
    }
    rep(i, 1, n+1){
        if(cnt[i] != 2){
            cout << ans << endl;
            return 0;
        }
    }

    ans = 0;
    rep(i, 1, n+1){
        if(r[i] == i) continue;
        swap(r[i], r[c[i]]);
        swap(c[r[i]], c[r[c[i]]]);
        ans++;

    }
    cout << ans << endl;
    
    return 0;
}