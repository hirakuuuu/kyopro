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
// https://atcoder.jp/contests/arc148/tasks/arc148_d

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(2*n);
    map<int, int> cnt;
    rep(i, 0, 2*n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> c;
    for(auto bb: b){
        if(cnt[bb]%2){
            c.push_back(bb);
        }
    }

    bool f = c.size()%4 == 0;
    if(f){
        int cs = c.size()/4;
        rep(i, 0, cs){
            if(!((c[2*i]+c[2*i+1])%m == (c[2*(i+cs)]+c[2*(i+cs)+1])%m && (c[2*i]+c[2*(i+cs)+1])%m == (c[2*i+1]+c[2*(i+cs)])%m)){
                f = false;
                break;
            }
        }
    }
    if(f){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }
    return 0;
}