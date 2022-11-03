#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc273/tasks/abc273_e

struct Node {
    int val, par;

    Node(int v, int p): val(v), par(p){}
};

int main(){
    int q; cin >> q;
    vector<Node> vec;
    vec.push_back(Node(-1, 0));
    int v = 0;
    map<int, int > mp;
    while(q--){
        string s; cin >> s;
        if(s == "ADD"){
            int x; cin >> x;
            vec.push_back(Node(x, v));
            v = vec.size()-1;
        }else if(s == "DELETE"){
            v = vec[v].par;
        }else if(s == "SAVE"){
            int y; cin >> y;
            mp[y] = v;
        }else if(s == "LOAD"){
            int z; cin >> z;
            v = mp[z];
        }
        cout << vec[v].val << ' ';
    }
    cout << endl;
    
    return 0;
}