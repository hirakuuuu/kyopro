#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

const int MAX_K = 2000000001;
struct node { 
    int key, parent=MAX_K, left=MAX_K, right=MAX_K; 

    void print(int i){
        printf("node %d: key = %d, ", i, key);
        if(parent != MAX_K) printf("parent key = %d, ", parent);
        if(left != MAX_K) printf("left key = %d, ", left);
        if(right !=  MAX_K) printf("right key = %d, ", right); 
        printf("\n");
    }

};
vector<node> tree(255);


int main(){
    int h; cin >> h;
    rep(i, 1, h+1){
        cin >> tree[i].key;
    }
    rep(i, 1, h+1){
        if(i > 1) tree[i].parent = tree[i/2].key;
        if(h >= 2*i) tree[i].left = tree[2*i].key;
        if(h >= 2*i+1) tree[i].right = tree[2*i+1].key;
        tree[i].print(i);
    }
}