#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

string s;
char f(ll t, ll k){
    if(t == 0) return s[k];
    else if(k == 0) return ('A'+((s[0]-'A')+t)%3);
    else return ('A'+((f(t-1, (k-k%2)/2)-'A')+1+k%2)%3);
}

int main(){
    cin >> s;
    int q; cin >> q;
    vector<char> ans;
    while(q--){
        ll t, k; cin >> t >> k;
        ans.push_back(f(t, k-1));
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
}