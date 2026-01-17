#pragma once
#include <vector>
using namespace std;

struct ordertree{
    int n;
    vector<int> tree;

    ordertree(int n):n(n),tree(4*n,0){}

    void build(int node,int l,int r){
        if(l==r){
            tree[node]=1;
            return;
        }
        int m=(l+r)>>1;
        build(node<<1,l,m);
        build(node<<1|1,m+1,r);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }

    int kth(int node,int l,int r,int k){
        if(l==r){
            return l;
        }
        int m=(l+r)>>1;
        if(tree[node<<1]>=k){
            return kth(node<<1,l,m,k);
        }
        return kth(node<<1|1,m+1,r,k-tree[node<<1]);
    }

    void remove(int node,int l,int r,int pos){
        if(l==r){
            tree[node]=0;
            return;
        }
        int m=(l+r)>>1;
        if(pos<=m){
            remove(node<<1,l,m,pos);
        }else{
            remove(node<<1|1,m+1,r,pos);
        }
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }
};
