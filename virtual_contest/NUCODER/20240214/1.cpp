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
// 

int main(){
    string s; cin >> s;
    stack<char> stc;
    rep(i, 0, s.size()){
        if(stc.size() >= 2){
            char b = stc.top(); stc.pop();
            char a = stc.top(); stc.pop();
            string c;
            c += a;
            c += b;
            c += s[i];
            if(c != "ABC"){
                stc.push(a);
                stc.push(b);
                stc.push(s[i]);
            }
        }else{
            stc.push(s[i]);
        }
    }
    string t;
    while(!stc.empty()){
        t += stc.top(); stc.pop();
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
    
    return 0;
}