#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,b,e) for(int (i)=(b);(i)<(e);(i)++)

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}

void solve(){
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
	int n=sizeof(arr)/sizeof(int);
	int c=arr[0],t=arr[0];
	FOR(i,1,n){
		c=(c+arr[i]<arr[i])?(c+arr[i]):arr[i];
		if(t>c)t=c;
	}
	cout<<t<<endl;
}

