#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_f

/*
辞書順最小は前から貪欲法
・アルファベット小文字は26文字しかない
・aから順に採用するべき文字を探すのをk回繰り返せばよい
・事前に各文字の位置を昇順で記録した配列を用意しておけば、二分探索で十分高速に求まる
*/

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> a(26);
    rep(i, 0, n){
        a[s[i]-'a'].push_back(i);
    }

    string t = "";
    int r = 0;
    rep(i, 0, k){
        rep(j, 0, 26){
            auto itr = lower_bound(a[j].begin(), a[j].end(), r);
            if(itr == a[j].end()) continue; 
            int aa = *itr;
            if(aa <= n-k+t.size()){
                t += (char)'a'+j;
                r = aa+1;
                break;
            }
        }
    }


    cout << t << endl;
    
    return 0;
}