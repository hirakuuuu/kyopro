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
// https://atcoder.jp/contests/abc333/tasks/abc333_b

int main(){
    string s, t; cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int S = (s[1]-'A')-(s[0]-'A');
    int T = (t[1]-'A')-(t[0]-'A');
    vector<int> d = {0, 1, 2, 2, 1};
    if(d[S] == d[T]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}