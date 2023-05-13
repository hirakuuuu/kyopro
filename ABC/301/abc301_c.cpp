#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc301/tasks/abc301_c

int main(){
    string s, t; cin >> s >> t;
    int n = s.size();
    vector<int> cnt_s(26), cnt_t(26);
    int cnt_as = 0, cnt_at = 0;
    rep(i, 0, n){
        if(s[i] == '@') cnt_as++;
        else cnt_s[s[i]-'a']++;

        if(t[i] == '@') cnt_at++;
        else cnt_t[t[i]-'a']++;
    }

    string atcoder = "atcoder";
    bool ans = true;
    rep(i, 0, 26){
        char c = (char)('a'+i);
        bool f = true;
        rep(j, 0, 7){
            if(atcoder[j] == c){
                f = false;
            }
        }
        if(f){
            ans &= cnt_s[i] == cnt_t[i];
        }else{
            if(cnt_s[i] > cnt_t[i]){
                cnt_at -= cnt_t[i]-cnt_s[i];
            }else{
                cnt_as -= cnt_t[i]-cnt_s[i];
            }
        }
    }

    if(ans and cnt_at >= 0 and cnt_as >= 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}