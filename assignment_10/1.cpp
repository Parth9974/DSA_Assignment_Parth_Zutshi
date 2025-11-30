#include <iostream>
using namespace std;

int main(){
    int a[4]={1,2,3,1};
    int n=4;
    int h[100]={0};
    for(int i=0;i<n;i++){
        int k=a[i]%100;
        while(h[k]!=0 && h[k]!=a[i]) k=(k+1)%100;
        if(h[k]==a[i]){
            cout<<"true";
            return 0;
        }
        h[k]=a[i];
    }
    cout<<"false";
}
