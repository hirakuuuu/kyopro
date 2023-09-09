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
// https://atcoder.jp/contests/abc319/tasks/abc319_a

int main(){
    map<string, int> m;
    m["tourist"] = 3858;
    m["ksun48"] = 3679;
    m["Benq"] =  3658;
    m["Um_nik"] = 3648;
    m["apiad"] = 3638;
    m["Stonefeang"] = 3630;
    m["ecnerwala"] = 3613;
    m["mnbvmar"] = 3555;
    m["newbiedmy"] = 3516;
    m["semiexp"] = 3481;
    string s; cin >> s;
    cout << m[s] << endl;
    
    return 0;
}