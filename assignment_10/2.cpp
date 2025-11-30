#include <iostream>
using namespace std;

int main(){
    int x[4]={1,2,3,4};
    int y[4]={3,4,5,6};
    int h[100]={0};
    for(int i=0;i<4;i++){
        int k=x[i]%100;
        while(h[k]!=0) k=(k+1)%100;
        h[k]=x[i];
    }
    for(int j=0;j<4;j++){
        int k=y[j]%100;
        int f=0;
        while(h[k]!=0){
            if(h[k]==y[j]){ f=1; break; }
            k=(k+1)%100;
        }
        if(f) cout<<y[j]<<" ";
    }
}
