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
// https://atcoder.jp/contests/arc163/tasks/arc163_c

int main(){
    int T; cin >> T;
    while(T--){        
        int n; cin >> n;

        if(n == 1){
            cout << "Yes" << endl;
            cout << 1 << endl;
        }else if(n == 2){
            cout << "No" << endl;
        }else{
            set<int> s;
            s.insert(2);
            s.insert(3);
            s.insert(6);

            int tmp = 3;
            while(s.size() < n){
                auto itr = s.lower_bound(tmp);
                tmp++;
                if(itr == s.end()) break;

                int a = *itr;
                if(s.find(a+1) != s.end() || s.find(a*(a+1)) != s.end()) continue;
                s.erase(itr);
                s.insert(a+1);
                s.insert(a*(a+1));
            }
            cout << "Yes" << endl;
            for(auto ss: s){
                cout << ss << ' ';
            }
            cout << endl;
        }
    }
    
    return 0;
}