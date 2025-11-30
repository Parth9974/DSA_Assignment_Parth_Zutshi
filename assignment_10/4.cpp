#include <iostream>
using namespace std;

int main(){
    int a[6]={4,5,1,2,0,4};
    int n=6;
    int key[200]={0};
    int val[200]={0};
    for(int i=0;i<n;i++){
        int k=(a[i]+200)%200;
        while(key[k]!=0 || (key[k]==0 && val[k]!=0)){
            if(key[k]==a[i]) break;
            k=(k+1)%200;
        }
        if(key[k]==a[i]) val[k]++;
        else{
            key[k]=a[i];
            val[k]=1;
        }
    }
    for(int i=0;i<n;i++){
        int k=(a[i]+200)%200;
        while(key[k]!=a[i]) k=(k+1)%200;
        if(val[k]==1){
            cout<<a[i];
            break;
        }
    }
}
