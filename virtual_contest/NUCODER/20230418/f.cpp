#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    if(s.size() == 1){
        if(s == "8") cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if(s.size() == 2){
        int tmp1 = (s[1]-'0')*10+(s[0]-'0');
        int tmp2 = (s[0]-'0')*10+(s[1]-'0');
        if(tmp1%8 == 0 or tmp2%8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        vector<int> cnt(10);
        rep(i, 0, s.size()){
            cnt[s[i]-'0']++;
        }

        int tmp = 0;
        rep(i, 0, 1000/8){
            vector<int> need(10);
            need[tmp%10]++;
            need[(tmp%100)/10]++;
            need[(tmp%1000)/100]++;
            bool f = true;
            rep(j, 0, 10){
                if(need[j] > cnt[j]) f = false;
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }
            tmp += 8;
        }
        cout << "No" << endl;
    }


    
    return 0;
}