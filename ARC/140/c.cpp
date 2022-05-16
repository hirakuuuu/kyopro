#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc140/tasks/arc140_c


int f(vector<int> a){
    vector<int> p;
    rep(i, 0, a.size()-1){
        p.push_back(abs(a[i]-a[i+1]));
    }
    vector<int> lcs(200005, 100000000);
    int max_len = 0;
    rep(i, 0, p.size()){
        int pos = lower_bound(lcs.begin(), lcs.end(), p[i]) - lcs.begin();
        lcs[pos] = p[i];
        max_len = max(max_len, pos+1);
    }
    return max_len;
    
}

int main(){
    int n, x; cin >> n >> x;
    vector<int> a;
    rep(i, 1, n+1){
        if(i == x) continue;
        a.push_back(i);
    }

    int l = 0, r = n-2;
    vector<int> a1, a2;
    rep(i, 0, n-1){
        if(i%2){
            a1.push_back(a[l]);
            l++;
        }else{
            a1.push_back(a[r]);
            r--;
        }
    }
    l = 0, r = n-2;
    rep(i, 0, n-1){
        if(i%2 == 0){
            a2.push_back(a[l]);
            l++;
        }else{
            a2.push_back(a[r]);
            r--;
        }
    }
    a1.push_back(x);
    a2.push_back(x);
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());

    if(f(a1) < f(a2)) swap(a1, a2);
    for(auto aa: a1){
        cout << aa << " ";
    }
    cout << endl;




    return 0;
}