#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int main(){
    int n; cin >> n;
    // dはsの階差数列を3項ごとに累積和を取ったもの
    vector<ll> s(n), d(n-1);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n-1){
        d[i] = s[i+1]-s[i];
        // ここで累積和を取ってる
        if(i >= 3) d[i] += d[i-3];
    }
    // dの3項ごとの最小値を記録
    vector<ll> m(3, 0);
    rep(i, 0, n-1){
        m[i%3] = min(m[i%3], d[i]);
    }
    /*
    d[i]はs[i]の階差数列を，3項ごとに累積和を取ったもの
    3項目以降は，以下の式で計算できる
    a[i] = a[i%3]+d[i-3] (3 <= i)

    dを3つごとに見て最小値を記録
    m[0] = min(d[i] i%3 == 0)
    m[1] = min(d[i] i%3 == 1)
    m[2] = min(d[i] i%3 == 2)

    sum (= m[0]+m[1]+m[2]) が s[0] より多きければ、a[0], a[1], a[2]を良い感じにしてあげればいける！！！
    */
    
    // mの和を取る
    ll sum = m[0]+m[1]+m[2];
    // sum*(-1)がs[0]より大きければ，数列は作れる
    if(sum*(-1) <= s[0]){
      cout << "Yes" << endl;
      // 前3項は以下のようにすれば、
      vector<ll> ans = {-1*m[0], -1*m[1], s[0]+m[0]+m[1]};
      printf("%d %d %d", ans[0], ans[1], ans[2]);
      rep(i, 0, n-1){
        cout << " " << ans[i%3]+d[i];
      }
      cout << endl;
    }else cout << "No" << endl;
}