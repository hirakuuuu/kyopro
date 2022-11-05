#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc276/tasks/abc276_c

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];

    int pos = 0;
    for(int i = n-2; i >= 0; i--){
        if(p[i] > p[i+1]){
            pos = i;
            break;
        }
    }

    vector<int> q;
    rep(i, pos+1, n){
        q.push_back(p[i]);
    }

    int r = lower_bound(q.begin(), q.end(), p[pos])-q.begin()-1;
    int m = q[r];
    q[r] = p[pos];
    sort(q.begin(), q.end(), greater<int>());

    rep(i, 0, n){
        if(i < pos) cout << p[i] << ' ';
        else if(i == pos) cout << m << ' ';
        else cout << q[i-pos-1] << ' ';
    }
    cout << endl;


    return 0;
}