#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, q; cin >> n >> q;
    vector<int> a(400005);
    int s = 400005-n;
    rep(i, 0, n) cin >> a[s+i];
    vector<int> ans;
    while(q--){
        int t, x, y; cin >> t >> x >> y;
        if(t == 1){
            swap(a[s+x-1], a[s+y-1]);
        }else if(t == 2){
            s--;
            a[s] = a[s+n];
        }else{
            ans.push_back(a[s+x-1]);
        }
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
  
}