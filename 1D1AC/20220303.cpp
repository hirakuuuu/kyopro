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
    multiset<int> ms;
    int a;
    rep(i, 0, n){
        cin >> a;
        auto itr = ms.upper_bound((-1)*a);
        if(itr != ms.end()) ms.erase(itr);
        ms.insert((-1)*a);
    }
    cout << ms.size() << endl;
    return 0;
}