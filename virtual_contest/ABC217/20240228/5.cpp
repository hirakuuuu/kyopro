#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int q; cin >> q;
    multiset<int> ms;
    queue<int> que;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            que.push(x);
        }else if(t == 2){
            if(!ms.empty()){
                cout << *ms.begin() << endl;
                ms.erase(ms.begin());
            }else{
                cout << que.front() << endl;
                que.pop();
            }
        }else{
            while(!que.empty()){
                ms.insert(que.front()); que.pop();
            }
        }
    }
    
    return 0;
}