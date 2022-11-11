#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc233/tasks/abc233_e

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> ans;
    int kur = 0, pos = n-1;
    vector<int> acm(n+1);
    for(int i = n-1; i >= 0; i--){
        acm[i] = acm[i+1]+(s[i]-'0');
    }

    while(kur > 0 or pos >= 0){
        if(pos >= 0){
            int num = (kur+acm[0]-acm[pos+1])%10;
            kur = (kur+acm[0]-acm[pos+1])/10;
            ans.push_back(num);
            pos--;
        }else{
            ans.push_back(kur%10);
            kur /= 10;
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto &a: ans){
        cout << a;
    }
    cout << endl;
    
    return 0;
}