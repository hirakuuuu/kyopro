#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc166/tasks/abc166_f

int main(){
    ll n; cin >> n;
    vector<ll> a(3);
    rep(i, 0, 3) cin >> a[i];
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    string ans = "";

    rep(i, 0, n){
        if(a[s[i][0]-'A'] == 0 and a[s[i][1]-'A'] == 0){
            cout << "No" << endl;
            return 0;
        }else if(a[s[i][0]-'A'] == 0){
            a[s[i][0]-'A']++;
            ans += s[i][0];
            a[s[i][1]-'A']--;
        }else if(a[s[i][1]-'A'] == 0){
            a[s[i][0]-'A']--;
            a[s[i][1]-'A']++;
            ans += s[i][1];
        }else{
            if(a[0]+a[1]+a[2] == 2 and i < n-1 and s[i] != s[i+1]){
                int j = 3-(s[i+1][0]-'A')-(s[i+1][1]-'A');
                if(s[i][0]-'A' == j){
                    a[s[i][0]-'A']--;
                    a[s[i][1]-'A']++;
                    ans += s[i][1];
                }else{
                    a[s[i][0]-'A']++;
                    ans += s[i][0];
                    a[s[i][1]-'A']--;
                }
            }else{
                if(a[s[i][0]-'A'] > a[s[i][1]-'A']){
                    a[s[i][0]-'A']--;
                    a[s[i][1]-'A']++;
                    ans += s[i][1];
                }else{
                    a[s[i][0]-'A']++;
                    ans += s[i][0];
                    a[s[i][1]-'A']--;
                }
            }   
        }
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << ans[i] << endl;
    }
    return 0;
}