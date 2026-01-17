#include <iostream>
#include <vector>
#include "../ordertree.hpp"
using namespace std;
// List Removals
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    ordertree ot(n);
    ot.build(1,1,n);

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int pos=ot.kth(1,1,n,k);
        cout<<a[pos]<<" ";
        ot.remove(1,1,n,pos);
    }
}
