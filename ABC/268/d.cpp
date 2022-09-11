#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc268/tasks/abc268_d


void f(int i, int remain, vector<string> &s, vector<string> &t, string ans){
    if(remain < 0) return;

    if(i == s.size()){
        if(ans.size() >=3 and !binary_search(t.begin(), t.end(), ans)){
            cout << ans << endl;
            exit(0);
        }
        return;
    }
    
    if(ans.size() > 0 and ans.back() != '_'){
        f(i, remain, s, t, ans+"_");
    }else{
        f(i+1, remain, s, t, ans+s[i]);
        if(ans.size() > 0) f(i, remain-1, s, t, ans+"_");
    }

}

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);

    int len = 0;
    
    rep(i, 0, n){
        cin >> s[i];
        len += s[i].size();
    }
    sort(s.begin(), s.end());

    vector<string> t(m);
    rep(i, 0, m){
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    do{
        f(0, 16-(len+n-1), s, t, "");

    }while(next_permutation(s.begin(), s.end()));

    cout << -1 << endl;


    return 0;
}