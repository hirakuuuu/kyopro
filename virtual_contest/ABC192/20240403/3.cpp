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

int g1(int x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    return stoi(s);
}

int g2(int x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    return stoi(s);
}

int f(int x){
    return g1(x)-g2(x);
};

int main(){
    
    int n, k; cin >> n >> k;
    int ans = n;
    rep(i, 0, k){
        ans = f(ans);
    }
    cout << ans << endl;


    return 0;
}