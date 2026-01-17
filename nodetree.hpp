#pragma once
#include <vector>
using namespace std;

template<class t>
struct nodetree{
    int n;
    vector<t> tree;

    nodetree(int n):n(n),tree(2*n){}

    void build(const vector<t>& a){
        for(int i=0;i<n;i++){
            tree[n+i]=a[i];
        }
        for(int i=n-1;i>0;i--){
            tree[i]=t::merge(tree[i<<1],tree[i<<1|1]);
        }
    }

    void update(int pos,t val){
        pos+=n;
        tree[pos]=val;
        while(pos>1){
            pos>>=1;
            tree[pos]=t::merge(tree[pos<<1],tree[pos<<1|1]);
        }
    }

    t query(int l,int r){
        t resl=t::neutral();
        t resr=t::neutral();
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1){
                resl=t::merge(resl,tree[l++]);
            }
            if(r&1){
                resr=t::merge(tree[--r],resr);
            }
        }
        return t::merge(resl,resr);
    }
};
