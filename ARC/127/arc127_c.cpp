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
// https://atcoder.jp/contests/arc127/tasks/arc127_c

int main(){
    int n; cin >> n;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    bitset<1000005> b;
    rep(i, 0, s.size()){
        b.set(i, s[i]-'0');
    }
    rep(i, 0, s.size()){
        if(b.test(i)){
            b.set(i, 0);
            break;
        }else{
            b.set(i, 1);
        }
    }
    string t = "1";
    rrep(i, n-1, 0){
        if(!b.any()){
            break;
        }else if(b.test(i)){
            t += '1';
            b.set(i, 0);
        }else{
            t += '0';
            rep(j, 0, 1000005){
                if(b.test(j)){
                    b.set(j, 0);
                    break;
                }else{
                    b.set(j, 1);
                }
            }
        }
        //cout << t << ' ' << b << endl;
    }
    cout << t << endl;
    
    return 0;
}