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
	int n,k;
	cin>>n>>k;
	int a[n+1][k+1];
	int v[n];
	FOR(i,0,n)cin>>v[i];
	FOR(i,0,k+1)a[0][i]=1;
	FOR(i,0,n+1)a[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			a[i][j]=a[i-1][j]+a[i-1][j/v[i-1]];
		}
	}
	FOR(i,0,n+1){
	FOR(j,0,k+1)cout<<a[i][j]<<" ";
	cout<<endl;
	}
	cout<<a[n][k]<<endl;

}

