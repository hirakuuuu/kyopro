#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc252/tasks/abc252_b

int main(){
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    vector<int> b(k);
    int max_a = 0;
    rep(i, 0, n){
        int A; cin >> A;
        a[i] = {A, i+1};
        max_a = max(max_a, a[i].first);
    }
    sort(a.begin(), a.end());
    vector<int> max_i;
    int j = n-1;
    while(j >= 0 and a[j].first == max_a){
        max_i.push_back(a[j].second);
        j--;
    }
    bool f = false;
    rep(i, 0, k){
        cin >> b[i];
        for(auto aa: max_i){
            if(b[i] == aa) f = true;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;


    
    return 0;
}