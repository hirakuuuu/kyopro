#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc195/tasks/abc195_e

int main(){
    int n; cin >> n;
    string s, x; cin >> s >> x;
    reverse(s.begin(), s.end());
    reverse(x.begin(), x.end());
    
    vector<int> c;
    rep(i, 0, n-1){
        if(x[i] != x[i+1]) c.push_back(i+1);
    }
    c.push_back(n);

    vector<int> amari(7), cp_amari(7), mod7(7);
    rep(i, 0, 7){
        mod7[(i*10)%7] = i;
    }
    if(x[0] == 'A') amari[0] = 1;
    else rep(i, 1, 7) amari[i] = 1;
    int l = 0;
    for(auto r: c){
        rep(i, 0, 7) amari[i] ^= 1;
        rep(i, l, r){
            cp_amari = amari;
            rep(j, 0, 7) amari[j] = 0;
            rep(j, 0, 7){
                if(cp_amari[j]){
                    amari[mod7[(j-(s[i]-'0')+14)%7]] = 1;
                    amari[mod7[j]] = 1;
                }
            }
        }
        l = r;
    }

    if(amari[0]){
        if(x[n-1] == 'A') cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }else{
        if(x[n-1] == 'T') cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }

    
    return 0;
}