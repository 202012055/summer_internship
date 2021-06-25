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
	long long n,m,a;
	cin>>n>>m>>a;
	cout<<(long long)((ceil(double(n)/a)*ceil(double(m)/a)))<<endl;

}

