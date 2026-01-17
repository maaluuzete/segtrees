#include <iostream>
#include <vector>
#include "../nodetree.hpp"
using namespace std;
// Dynamic Range Sum Queries
struct sumnode{
    long long v;

    static sumnode merge(const sumnode& a,const sumnode& b){
        return {a.v+b.v};
    }

    static sumnode neutral(){
        return {0};
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<sumnode> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].v;
    }

    nodetree<sumnode> st(n);
    st.build(a);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int k;
            long long x;
            cin>>k>>x;
            st.update(k-1,{x});
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.query(l-1,r).v<<"\n";
        }
    }
}
