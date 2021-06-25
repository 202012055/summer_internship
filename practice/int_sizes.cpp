#include<bits/stdc++.h>
using namespace std;

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	int input[]={1,2,4,8};
	for(auto i:input){
		cout<<i<<" ";
		unsigned long long a=1;
	cout<<"max:"<<a-2<<endl;
		a<<=((i*8));
		cout<<(double)a<<endl;
	
	}

}

