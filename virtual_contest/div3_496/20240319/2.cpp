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
// div3_496

int main(){
    string s, t; cin >> s >> t;
    int pos_s = s.size()-1, pos_t = t.size()-1, len = 0;
    while(pos_s >= 0 && pos_t >= 0){
        if(s[pos_s] == t[pos_t]){
            len++;
            pos_s--;
            pos_t--;
        }else{
            break;
        }
    }
    cout << s.size()+t.size()-2*len << endl;
    return 0;
}