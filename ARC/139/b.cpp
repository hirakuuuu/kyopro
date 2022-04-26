#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc139/tasks/arc139_b

//こういうのはすっと通したい


int main(){
    int t; cin >> t;
    vector<ll> res;
    while(t--){
        ll n, a, b, x, y, z; cin >> n >> a >> b >> x >> y >> z;
        y = min(y, a*x);
        z = min(z, b*x);

        if(y*b > z*a){
            swap(a, b);
            swap(y, z);
        }

        ll ans = (1LL<<60), rest = 0;
        if(n/a+1 <= a){
            rep(i, 0, n/a+1){
                rest = n-i*a;
                ans = min(ans, y*i+min((rest/b)*z+(rest%b)*x, rest*x));
            }
        }else{
            rep(i, 0, min(a, n/b+1)){
                rest = n-i*b;
                ans = min(ans, z*i+min((rest/a)*y+(rest%a)*x, rest*x));
            }
        }
        res.push_back(ans);
    }

    for(auto rr: res){
        cout << rr << endl;
    }

    return 0;
}
