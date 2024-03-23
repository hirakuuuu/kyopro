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

int main(){
    int n, x; cin >> n >> x;
    x--;
    vector<int> rev(n);
    rep(i, 0, n){
        int a; cin >> a;
        a--;
        rev[i] = a;
    }
    int ans = 1;
    queue<int> que;
    que.push(x);
    vector<int> know(n);
    know[x] = true;
    while(!que.empty()){
        int q = que.front(); que.pop();
        if(know[rev[q]]) continue;
        ans++;
        know[rev[q]] = true;
        que.push(rev[q]);
    }
    cout << ans << endl;
    return 0;
}