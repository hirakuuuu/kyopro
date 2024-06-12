#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
s[i] = 'a', 'b', 'c' のとき, それぞれ d[i] = 0, 1, 2 とする.
このとき, 答えは sum{2^{i-1}*d[i]} になる.

potential = sum{2^{i-1}*d[i]} とすると、操作によって potential は必ず1以上減少する.
また、potential が 1 だけ減るような操作を毎回選ぶことができる.
*/

int main(){
    int n; cin >> n;
    string s; cin >> s;
    auto f = [&](auto self, int pos) -> ll {
        if(pos == n) return 0LL;

        ll res = 0;
        if(s[pos] == 'a'){
            res += self(self, pos+1);
        }else if(s[pos] == 'b'){
            res += (1LL<<pos)+self(self, pos+1);
        }else{
            res += (1LL<<pos+1)+self(self, pos+1);
        }
        return res;
    };
    cout << f(f, 0) << endl;


    return 0;
}