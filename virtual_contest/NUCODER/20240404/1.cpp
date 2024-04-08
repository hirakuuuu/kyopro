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
    int n; cin >> n;
    string s; cin >> s;
    stack<char> stc;
    int cnt = 0;
    rep(i, 0, n){
        if(s[i] == '('){
            stc.push(s[i]);
            cnt++;
        }else if(s[i] == ')'){
            stc.push(s[i]);
            if(cnt){
                while(stc.top() != '('){
                    stc.pop();
                }
                stc.pop();
                cnt--;
            }
        }else{
            stc.push(s[i]);
        }
    }
    string ans;
    while(!stc.empty()){
        ans += stc.top(); stc.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
    return 0;
}