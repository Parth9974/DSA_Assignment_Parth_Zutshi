#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements in the array";
    cin>>n;
    int arr[n];
    
    int ch;
    cout<<"enter the choice 1 for creation 2 for display 3 for insertion 4 for deletion 5 for linear search 6 for exit";
    cin>>ch;
    switch(ch)
    {
        case 1:
        cout<<"enter the elements in the array";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        break;

        case 2:
        cout<<"enter the elements in the array";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i];
        }
        break;

        case 3:
        cout<<"enter the elements in the array";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int idx,num;
        cout<<"enter the index to be inserted and the num which inserted"<<endl;
        cin>>idx>>num;
            for(int i=n;i>=0;i--)
        {
            if(i==idx)
            {
                arr[i]=num;
                break;
            }
            else{
                arr[i]=arr[i-1];
            }
        }
        cout<<"the new array is:"<<endl;
        for(int i=0;i<n+1;i++)
        {
            cout<<arr[i]<<" ";
        }
        break;

        case 4:
        cout<<"enter the elements in the array";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"enter the index of the element to be deleted"<<endl;
        cin>>idx;


        for(int i=idx;i<n;i++)
        {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
        }
        cout<<"the new array is:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        break;

        case 5:
        cout<<"enter the elements in the array";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
            cout<<"enter the element to be searched"<<endl;
            cin>>num;
            for(int i=0;i<n;i++)
            {
                if(num==arr[i])
                idx=i;
            }
            cout<<"element found at index "<<idx<<endl;
        break;

        case 6:
            cout<<"exiting program....."<<endl;
            exit(0);
            break;
        
        default:
        cout<<"wrong choice";

}
}