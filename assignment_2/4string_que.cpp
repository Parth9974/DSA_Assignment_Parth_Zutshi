#include <iostream>
#include <string>
using namespace std;

void concatenate(string s1,string s2)
{
    for(int i=0;i<(int)(s1.length()+s2.length());i++)
    {
        if(i<(int)s1.length())
        {
            cout<<s1[i];
        }
        else if(i>=(int)s1.length()){
            cout<<s2[i-s1.length()];
        }
    }
    cout<<endl;
}
void reverse(string s)
{
    int flag=s.length()-1;
    for(int i=0;i<(int)s.length();i++)
    {
        if(i>=flag)
        {
            break;
        }
        else{
            char temp=s[i];
            s[i]=s[flag];
            s[flag]=temp;
            flag--;
        }
    }
    for(int i=0;i<(int)s.length();i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
void delete_vowel(string s){
    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i')
        {
            s.erase(i,i+1);
        }
    }
    for(int i=0;i<(int)s.length();i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
void sort_string(string s)
{
    for(int i=0;i<(int)s.length();i++)
    {
        for(int j=i+1;j<(int)s.length();j++)
        {
            if((int)s[i]>(int)s[j])
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    for(int i=0;i<(int)s.length();i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
void convert_string(string s){
    for(int i=0;i<(int)s.length();i++)
    {
        if((int)s[i]>=65 && (int)s[i]<=91)
        {
            s[i]=(char)((int)s[i]+32);
        }
        
    }
    for(int j=0;j<(int)s.length();j++)
    {
        cout<<s[j];
    }
    cout<<endl;
}
int main()
{
    string str1,str2;
    cout<<"enter two strings:";
    cin>>str1>>str2;
    concatenate(str1,str2);
    reverse(str1);
    reverse(str2);
    delete_vowel(str1);
    delete_vowel(str2);
    sort_string(str1);
    sort_string(str2);
    convert_string(str1);
    convert_string(str2);
}