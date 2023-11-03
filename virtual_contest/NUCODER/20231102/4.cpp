#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

string s;
int f(ll t, ll k){
    if(k == 0){
        return ((s[0]-'A')+t%3)%3;
    }
    if(t == 0){
        return s[k]-'A';
    }

    if(k%2 == 0){
        return (f(t-1, k/2)+1)%3;
    }

    return (f(t-1, k/2)+2)%3;
}

int main(){
    cin >> s;
    int q; cin >> q;
    string abc = "ABC";
    while(q--){
        ll t, k; cin >> t >> k;
        int ans = f(t, k-1);
        cout << abc[ans] << endl;
    }
    
    return 0;
}