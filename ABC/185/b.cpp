#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m, t; cin >> n >> m >> t;
    vector<int> a, b;
    b.push_back(0);
    rep(i, 0, m){
        int A, B; cin >> A >> B;
        a.push_back(A);
        b.push_back(B);
    }
    a.push_back(t);
    int juden = n;
    bool f = true;
    rep(i, 0, m+1){
        juden = max(0, juden-a[i]+b[i]);
        if(juden == 0) f = false;
        if(i < m) juden = min(n, juden+b[i+1]-a[i]);
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;  
}