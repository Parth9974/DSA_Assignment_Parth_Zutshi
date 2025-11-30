#include <iostream>
using namespace std;

int main(){
    int a[6]={2,3,2,4,3,2};
    int n=6;
    int key[100]={0};
    int val[100]={0};
    for(int i=0;i<n;i++){
        int k=a[i]%100;
        while(key[k]!=0 && key[k]!=a[i]) k=(k+1)%100;
        if(key[k]==0){
            key[k]=a[i];
            val[k]=1;
        } else val[k]++;
    }
    for(int i=0;i<100;i++){
        if(key[i]!=0) cout<<key[i]<<" "<<val[i]<<endl;
    }
}
