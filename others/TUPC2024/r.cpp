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
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();

        int cnt_p = 0, cnt_n = 0;
        rep(i, 0, n){
            if(s[i] == '(') cnt_p++;
            if(s[i] == ')') cnt_n++;
        }
        if(abs(cnt_p-cnt_n) >= 2){
            cout << "Second" << endl;
            continue;
        }else if(cnt_p == cnt_n && cnt_p != n/2){
            cout << "Second" << endl;
            continue;
        }

        if(cnt_p > cnt_n){
            // できるだけ右のはてなに ) を置く
            rrep(i, n-1, 0){
                if(s[i] == '?'){
                    s[i] = ')';
                    break;
                }
            }
        }else if(cnt_p < cnt_n){
            // できるだけ左のはてなに () を置く
            rep(i, 0, n){
                if(s[i] == '?'){
                    s[i] = '(';
                    break;
                }
            }
        }

        bool ok = true;
        // 後手が ( を置いてく場合
        {
            string s_ = s;
            int cnt = 0;
            rrep(i, n-1, 0){
                if(s_[i] == '?'){
                    if(cnt == 0) s_[i] = '(';
                    if(cnt == 1) s_[i] = ')';
                    cnt = 1-cnt;
                }
            }
            stack<char> stc;
            rep(i, 0, n){
                if(s_[i] == '('){
                    stc.push('(');
                }else{
                    if(!stc.empty() && stc.top() == '(') stc.pop();
                    else ok = false;
                }
            }
            if(!stc.empty()) ok = false;
        }
        // 後手が ) を置いてく場合
        {
            string s_ = s;
            int cnt = 0;
            rep(i, 0, n){
                if(s_[i] == '?'){
                    if(cnt == 0) s_[i] = ')';
                    if(cnt == 1) s_[i] = '(';
                    cnt = 1-cnt;
                }
            }
            stack<char> stc;
            rep(i, 0, n){
                if(s_[i] == '('){
                    stc.push('(');
                }else{
                    if(!stc.empty() && stc.top() == '(') stc.pop();
                    else ok = false;
                }
            }
            if(!stc.empty()) ok = false;
        }
        
        if(ok) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    
    return 0;
}