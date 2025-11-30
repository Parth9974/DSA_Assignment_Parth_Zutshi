#include <iostream>
using namespace std;

class node{
public:
    int d;
    node* l;
    node* r;
    node(int x){ d=x; l=r=NULL; }
};

int chk(node* t,int h[],int sz){
    if(!t) return 0;
    int k=t->d%sz;
    while(h[k]!=0 && h[k]!=t->d) k=(k+1)%sz;
    if(h[k]==t->d) return 1;
    h[k]=t->d;
    return chk(t->l,h,sz) || chk(t->r,h,sz);
}

int main(){
    node* a=new node(10);
    a->l=new node(5);
    a->r=new node(15);
    a->l->l=new node(3);
    a->l->r=new node(5);

    int h[200]={0};
    if(chk(a,h,200)) cout<<"Duplicates Found";
    else cout<<"No Duplicates";
}
