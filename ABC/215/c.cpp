#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc215/tasks/abc215_c

int main(){
    string s; cin >> s;
    int k; cin >> k;

    sort(s.begin(), s.end());

    int cnt = 1;

    do{
        if(cnt == k){
            cout << s << endl;
            break;
        }
        cnt++;

    }while(next_permutation(s.begin(), s.end()));
    
    return 0;
}