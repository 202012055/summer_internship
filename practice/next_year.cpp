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
	int a;
	cin>>a;
	auto isit=[](int x){
		string xs=to_string(x);
		bool f[10]{};
		for(auto c:xs){
			if(f[c-'0'])return false;
			f[c-'0']=true;
		}
		return true;
	};
	while(!isit(++a));
	cout<<a<<endl;

}

