#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc267/tasks/abc267_b

int main(){
    string s; cin >> s;
    if(s[0] == '1'){
        cout << "No" << endl;
        return 0;
    }


    vector<vector<int>> line(7);
    line[0].push_back(6);
    line[1].push_back(3);
    line[2].push_back(1);
    line[2].push_back(7);
    line[3].push_back(4);
    line[4].push_back(2);
    line[4].push_back(8);
    line[5].push_back(5);
    line[6].push_back(9);

    rep(i, 0, 7){
        rep(j, i+2, 7){
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;

            for(auto p: line[i]){
                if(s[p] == '1') cnt1 = 1;
            }
            for(auto p: line[j]){
                if(s[p] == '1') cnt2 = 1;
            }

            rep(k, i+1, j){
                bool f = false;
                for(auto p: line[k]){
                    if(s[p] == '1') f = true;
                }
                if(f) continue;
                cnt3 = 1;
                break;
            }

            if(cnt1+cnt2+cnt3 == 3){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    
    return 0;
}