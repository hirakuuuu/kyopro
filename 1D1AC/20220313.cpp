#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n+1);
    int mg = 10005;
    rep(i, 0, n+1){
        cin >> a[i];
        if(i > 0) mg = min(mg, abs(a[i]-a[i-1]));
    }

    vector<vector<int>> b(10005, vector<int>(105));
    rep(i, 0, mg){
        rep(j, 0, n+1){
            b[i][j] = (a[j]+i)/mg;
        }

    }
    cout << mg << endl;
    rep(i, 0, mg){
        rep(j, 0, n+1){
            if(j > 0) cout << ' ';
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}