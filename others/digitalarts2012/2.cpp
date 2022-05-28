#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/digitalarts2012/tasks/digitalarts_2

int main(){
    string s; cin >> s;
    int hash = 0;
    for(auto ss: s){
        hash += ss-'a'+1;
    }

    if(hash == 1 or hash == 26*20){
        cout << "NO" << endl;
        return 0;
    }

    string ans1;
    while(hash){
        if(hash >= 26){
            ans1 += 'z';
            hash -= 26;
        }else{
            char b = 'a'+hash-1;
            ans1 += b;
            hash = 0;
        }
    }
    string ans2 = ans1;
    reverse(ans2.begin(), ans2.end());
    string ans3 = ans1;
    if(ans1 == ans2){
        int n = ans3.size()-1;
        ans3[n] = ans3[n]-1;
        ans3 += 'a';



    }
    

    if(ans1 != s) cout << ans1 << endl;
    else if(ans2 != s) cout << ans2 << endl;
    else cout << ans3 << endl;

    
    return 0;
}