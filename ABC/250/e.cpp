#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_e


int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> a_size(n), b_size(n);
    vector<int> a_, b_;
    set<int> set_a, set_b;
    rep(i, 0, n){
        cin >> a[i];
        set_a.insert(a[i]);
        a_size[i] = set_a.size();
        if(i == 0 or a_size[i] > a_size[i-1]) a_.push_back(a[i]);
    }
    rep(i, 0, n){
        cin >> b[i];
        set_b.insert(b[i]);
        b_size[i] = set_b.size();
        if(i == 0 or b_size[i] > b_size[i-1]) b_.push_back(b[i]);
    }

    int k = min(a_.size(), b_.size());
    vector<bool> s(k);
    set<int> S;
    rep(i, 0, k){
        if(S.find(a_[i]) == S.end()) S.insert(a_[i]);
        else S.erase(a_[i]);
        if(S.find(b_[i]) == S.end()) S.insert(b_[i]);
        else S.erase(b_[i]);
        s[i] = S.size();
    }

    vector<string> ans;
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(a_size[x-1] != b_size[y-1]) ans.push_back("No");
        else{
            if(s[a_size[x-1]-1]) ans.push_back("No");
            else ans.push_back("Yes");
        }

    }

    for(auto aa: ans){
        cout << aa << endl;
    }  
    return 0;
}