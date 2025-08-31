#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements of the array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int num_not;
    cout<<"enter a random no which is not in the array"<<endl;
    cin>>num_not;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                arr[j]=num_not;
            }
        }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=num_not)
        {
            flag++;
        }
        else{
            continue;
        }
    }
    cout<<"the no of unique elements:"<<flag;
}