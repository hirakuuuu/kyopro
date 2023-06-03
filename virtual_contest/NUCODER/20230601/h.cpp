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

int main(){
    ll a, b; cin >> a >> b;
    int k; cin >> k;
    vector<ll> yakusu;
    for(int i = 1; i<= min(a, b); i++){
        if(a%i == 0 and b%i == 0){
            yakusu.push_back(i);
        }
    }

    reverse(yakusu.begin(), yakusu.end());
    cout << yakusu[k-1] << endl;
    return 0;
}