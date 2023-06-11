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
// https://atcoder.jp/contests/arc129/tasks/arc129_c

int main(){
    int n; cin >> n;
    vector<int> a;
    rep(i, 1, 2001){
        a.push_back(i*(i-1)/2);
    }
    vector<int> c(6);
    int rest = n;
    rep(i, 0, 7){
        int pos = upper_bound(a.begin(), a.end(), rest)-a.begin();
        pos--;
        c[i] = pos+1;
        rest -= a[pos];
    }
    c[0]--;

    string ans;
    string div_char = "7123456";
    int div = 0, ten = 1;
    rep(i, 0, 7){
        rep(j, 0, c[i]){
            rep(k, 0, 7){
                if((div+ten*k)%7 == i){
                    ans += div_char[k];
                    div = i;
                    ten = ten*10%7;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

 


    
    return 0;
}