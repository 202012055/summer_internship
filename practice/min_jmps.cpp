// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    int reach=0,old,jmp=-1,c=0;
    do{
        jmp++;
	cout<<jmp<<":------\n";
        old=reach;
        while(c<n && c<=old ){
            reach=max(reach,c+arr[c]);
		cout<<"curr:"<<c<<":"<<arr[c]<<" reach:"<<reach<<endl;
            c++;
        }
    }while(c<n || old==reach);
    if(c==n)return jmp;
    return -1;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
