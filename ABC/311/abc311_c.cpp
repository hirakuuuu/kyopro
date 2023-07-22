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
// https://atcoder.jp/contests/abc311/tasks/abc311_c

vector<bool> seen(200005);
int dfs(int pos, vector<int> &a){
    if(seen[pos]) return pos;
    seen[pos] = true;
    return dfs(a[pos], a);
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }


    int pos = dfs(0, a);
    vector<bool> used(n);
    vector<int> ans = {pos};
    int tmp = a[pos];
    while(tmp != pos){
        ans.push_back(tmp);
        tmp = a[tmp];
    }

    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa+1 << ' ';
    }
    cout << endl;


    return 0;
}