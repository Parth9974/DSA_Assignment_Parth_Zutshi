#include <iostream>
using namespace std;

class node{
public:
    int v;
    node* nxt;
    node(int x){ v=x; nxt=NULL; }
};

int main(){
    node* a=new node(1);
    a->nxt=new node(2);
    a->nxt->nxt=new node(3);
    a->nxt->nxt->nxt=new node(4);
    a->nxt->nxt->nxt->nxt=a->nxt;

    long long h[500]={0};
    node* t=a;
    while(t){
        long long x=(long long)t;
        int k=x%500;
        while(h[k]!=0 && h[k]!=x) k=(k+1)%500;
        if(h[k]==x){
            cout<<"true";
            return 0;
        }
        h[k]=x;
        t=t->nxt;
    }
    cout<<"false";
}
