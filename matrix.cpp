#include <iostream>
using namespace std;

int main()
{
    int rows,cols;
    int choice;
    cout<<"Enter 1 for directed "<<endl<<"2 for undirected"<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter the no of rows and cols"<<endl;
    cin>>rows>>cols;
    int arr[rows][cols];
    char ans;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<"if v"<<i+1<<" is directed to v"<<j+1<<endl;
            cin>>ans;
            if(ans=='y')
            {
                arr[i][j]=1;
            }
            else{
                arr[i][j]=0;
            }
        }
    }
    int indeg=0;
    int outdeg=0;
    int self=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==j)
            {
                if(arr[i][j]==1)
                {
                    self++;
                    outdeg++;
                }
            }
            else{
                if(arr[i][j]==1)
                outdeg++;
            }
        }
        cout<<"Outdegree for v"<<i+1<<" is : "<<outdeg<<endl;
        outdeg=0;
    }
    for(int j=0;j<cols;j++)
    {
        for(int i=0;i<rows;i++)
        {
            if(arr[i][j]==1)
            {
                indeg++;
            }
        }
        cout<<"Indegree for v "<<j+1<<" is :"<<indeg<<endl;
        indeg=0;
    }
    cout<<"Self loops : "<<self<<endl;
    cout<<"Adjacency Matrix : "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    }
    else if(choice==2)
    {
        int rows,cols;
        cout<<"Enter the rows and columns"<<endl;
        cin>>rows>>cols;
        int arr[rows][cols];
        char ans;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==j)
                {
                    arr[i][j]=0;
                }
                else{
                    cout<<"If v"<<i+1<<" is connected to v"<<j+1<<endl;
                    cin>>ans;
                    if(ans=='y')
                    {
                        arr[i][j]=1;
                    }
                    else{
                        arr[i][j]=0;
                    }
                }
            }
        }
        int deg=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j]==1)
                {
                    deg++;
                }
            }
            cout<<"degree for v"<<i+1<<" is :"<<deg<<endl;
            deg=0;
        }
        cout<<"Adjacency Matrix"<<endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}