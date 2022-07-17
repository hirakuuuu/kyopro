#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc260/tasks/abc260_b

int main(){
    int n, x, y, z; cin >> n >> x >> y >> z;
    vector<pii> a(n), b(n), c(n);
    rep(i, 0, n){
        cin >> a[i].first;
        a[i].second = -i;
    }
    rep(i, 0, n){
        cin >> b[i].first;
        b[i].second = -i;
    }

    rep(i, 0, n){
        c[i] = {a[i].first+b[i].first, -i};
    }


    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    vector<int> pass(n);

    rep(i, 0, x){
        pass[-a[i].second] = 1;   
    }

    int cnt = 0, j = 0;
    while(cnt < y){
        if(pass[-b[j].second] == 0){
            pass[-b[j].second] = 1;
            cnt++;
        }
        j++;
    }

    cnt = 0, j = 0;
    while(cnt < z){
        if(pass[-c[j].second] == 0){
            pass[-c[j].second] = 1;
            cnt++;
        }
        j++;
    }

    rep(i, 0, n){
        if(pass[i]) cout << i+1 << endl;
    }






    
    return 0;
}