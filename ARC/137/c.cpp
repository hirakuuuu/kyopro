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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    if(a[n-1]-a[n-2] > 1){
        cout << "Alice" << endl;
    }else{
        if((a[n-1]+1-n)%2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}