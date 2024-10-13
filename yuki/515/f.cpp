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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    stack<char> stc, stc2;
    rep(i, 0, n){
        if(s[i] != '='){
            stc2.push(s[i]);
        }

        if(s[i] == '>'){
            stc2.pop();
            if(!stc.empty() && stc.top() == '=' && !stc2.empty() && stc2.top() == '<'){
                // 取り除ける
                stc2.pop();
                while(!stc.empty() && stc.top() == '=') stc.pop();
                stc.pop();
            }else{
                stc.push('>');
                stc2.push('>');
            }
        }else{
            stc.push(s[i]);
        }
    }
    cout << stc.size() << endl;
    return 0;
}