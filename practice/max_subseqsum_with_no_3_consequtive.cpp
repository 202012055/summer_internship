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
	int n;cin>>n;
	int ans[n+3];
	int v[n+3];
	v[0]=v[1]=v[2]=0;
	ans[0]=ans[1]=ans[2]=0;
	FOR(i,3,n+3)cin>>v[i];
	FOR(i,3,n+3)ans[i]=v[i]+max(ans[i-2],ans[i-3]+v[i-1]);
	cout<<max({ans[n],ans[n+1],ans[n+2]})<<endl;


}

