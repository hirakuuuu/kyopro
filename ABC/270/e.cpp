#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<pll> b(n);
    rep(i, 0, n) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    ll rest = k, ate = 0, cnt = n, pos = 0;

    rep(i, 0, n){
        if((b[i].first-ate)*cnt <= rest){
            rest -= (b[i].first-ate)*cnt;
            ate = b[i].first;
            cnt--;
        }else{
            ate += rest/cnt;
            pos = rest%cnt;
            break;
        }
    }

    // cout << ate << " " << pos << endl;

    ll cnt_ = 0;
    rep(i, 0, n){
        if(i) cout << ' ';
        if(a[i] <= ate) cout << 0;
        else if(cnt_ < pos){
            cout << a[i]-ate-1;
            cnt_++;
        }else cout << a[i]-ate;
    }

    cout << endl;

    
    return 0;
}