#pragma once
#include <algorithm>
using namespace std;

struct implicittree{
    struct node{
        long long val;
        node* l;
        node* r;
        node():val(0),l(nullptr),r(nullptr){}
    };

    node* root;
    long long llim,rlim;

    implicittree(long long l,long long r):llim(l),rlim(r){
        root=new node();
    }

    void update(node*& cur,long long l,long long r,long long pos,long long val){
        if(!cur){
            cur=new node();
        }
        if(l==r){
            cur->val=val;
            return;
        }
        long long m=(l+r)>>1;
        if(pos<=m){
            update(cur->l,l,m,pos,val);
        }else{
            update(cur->r,m+1,r,pos,val);
        }
        long long lv=cur->l?cur->l->val:0;
        long long rv=cur->r?cur->r->val:0;
        cur->val=max(lv,rv);
    }

    long long query(node* cur,long long l,long long r,long long ql,long long qr){
        if(!cur||r<ql||l>qr){
            return 0;
        }
        if(ql<=l&&r<=qr){
            return cur->val;
        }
        long long m=(l+r)>>1;
        return max(query(cur->l,l,m,ql,qr),
                   query(cur->r,m+1,r,ql,qr));
    }
};
