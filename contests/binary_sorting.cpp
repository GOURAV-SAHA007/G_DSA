#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ones;
    int best; 
    int len;
    int lazy; 
    Node(): ones(0), best(-1000000000), len(0), lazy(-1) {}
};

struct SegTree {
    int n;
    vector<Node> st;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n=_n;
        st.assign(4*n+5, Node());
        if(n) build(1,1,n);
    }
    void build(int p,int l,int r){
        st[p].len = r-l+1;
        st[p].lazy = -1;
        if(l==r){
            st[p].ones = 0;
            st[p].best = 0;
            return;
        }
        int m=(l+r)/2;
        build(p<<1,l,m);
        build(p<<1|1,m+1,r);
        pull(p);
    }
    void apply_set(int p,int v){
        st[p].lazy = v;
        if(v==0){
            st[p].ones = 0;
            st[p].best = 0;
        } else {
            st[p].ones = st[p].len;
            st[p].best = -1000000000;
        }
    }
    void push(int p){
        if(st[p].lazy!=-1){
            apply_set(p<<1, st[p].lazy);
            apply_set(p<<1|1, st[p].lazy);
            st[p].lazy = -1;
        }
    }
    void pull(int p){
        st[p].ones = st[p<<1].ones + st[p<<1|1].ones;
        st[p].best = max(st[p<<1].best, st[p<<1].ones + st[p<<1|1].best);
    }
    void update(int p,int l,int r,int ql,int qr,int v){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            apply_set(p,v);
            return;
        }
        push(p);
        int m=(l+r)/2;
        update(p<<1,l,m,ql,qr,v);
        update(p<<1|1,m+1,r,ql,qr,v);
        pull(p);
    }
    void update_range(int l,int r,int v){ if(l>r) return; update(1,1,n,l,r,v); }
    int total_ones(){ return st[1].ones; }
    int get_best(){ return st[1].best; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int N,Q; cin>>N>>Q;
        SegTree seg(N);
        for(int qi=0; qi<Q; ++qi){
            int type; cin>>type;
            if(type==0){
                int L,R; cin>>L>>R;
                seg.update_range(L,R,0);
            } else if(type==1){
                int L,R; cin>>L>>R;
                seg.update_range(L,R,1);
            } else {
                int ones = seg.total_ones();
                int zeros = N - ones;
                seg.update_range(1, zeros, 0);
                seg.update_range(zeros+1, N, 1);
            }
            int best = seg.get_best();
            if(best < 0) cout << 1 << '\n';
            else cout << (best + 1) << '\n';
        }
    }
    return 0;
}