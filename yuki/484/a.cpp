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
    int k; cin >> k;
    vector<string> s(16);
    string nupc = "NUPC";
    rep(i, 0, 16){
        rep(j, 0, 8){
            if(j%2 == 0){
                s[i] += nupc[j/2];
            }else{
                if((i>>(j/2))&1) continue;
                s[i] += s[i];
            }
        }
    }
    sort(s.begin(), s.end());
    cout << s[k-1] << endl;
    
    return 0;
}