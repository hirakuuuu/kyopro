#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    stack<pii> stc;
    map<int, int> m; 
    int pre = 1, cnt = 1;
    rep(i, 0, n){
        int a; cin >> a;
        if(a == pre){
            cnt++;
            stc.push(make_pair(a, cnt));
            if(a == cnt){
                rep(j, 0, a) stc.pop();
                if(stc.size()) cnt = stc.top().second;
                else cnt = 1;
            }
        }else{
            cnt = 1;
            stc.push(make_pair(a, cnt));
        }
        cout << stc.size() << endl;
        if(stc.size()) pre = stc.top().first;
        else pre = 1;
    }
    return 0;
  
}