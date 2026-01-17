#pragma once
#include <vector>
using namespace std;

struct lazytree{
    int n;
    vector<long long> tree,lazy;

    lazytree(int n):n(n){
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
    }

    void push(int node,int l,int r){
        if(lazy[node]==0){
            return;
        }
        tree[node]+=(r-l+1)*lazy[node];
        if(l!=r){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }

    void update(int node,int l,int r,int ql,int qr,long long val){
        push(node,l,r);
        if(r<ql||l>qr){
            return;
        }
        if(ql<=l&&r<=qr){
            lazy[node]+=val;
            push(node,l,r);
            return;
        }
        int m=(l+r)>>1;
        update(node<<1,l,m,ql,qr,val);
        update(node<<1|1,m+1,r,ql,qr,val);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }

    long long query(int node,int l,int r,int ql,int qr){
        push(node,l,r);
        if(r<ql||l>qr){
            return 0;
        }
        if(ql<=l&&r<=qr){
            return tree[node];
        }
        int m=(l+r)>>1;
        return query(node<<1,l,m,ql,qr)
             + query(node<<1|1,m+1,r,ql,qr);
    }
};
