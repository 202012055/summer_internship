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
	cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}

void solve(){
	int t;
	cin>>t>>t>>t;
	string a,b,c;
	cin>>a>>b>>c;
	int as=a.size();
	int bs=b.size();
	int cs=c.size();
	int ans[as+1][bs+1][cs+1];
	for(int i=0;i<=as;i++)
		for(int j=0;j<=bs;j++)
			ans[i][j][0]=0;
	for(int i=0;i<=bs;i++)
		for(int j=0;j<=cs;j++)
			ans[0][i][j]=0;
	for(int i=0;i<=as;i++)
		for(int j=0;j<=cs;j++)
			ans[i][0][j]=0;
	for(int i=1;i<=as;i++)
		for(int j=1;j<=bs;j++)
			for(int k=1;k<=cs;k++){
				if(a[i]==b[j] && b[j]==c[k]){
					ans[i][j][k]=ans[i-1][j-1][k-1]+1;
				}else{
					ans[i][j][k]=max({
							ans[i-1][j][k],
							ans[i][j][k-1],
							ans[i][j-1][k],
							ans[i][j-1][k-1],
							ans[i-1][j-1][k],
							ans[i-1][j][k-1]
							});
				}
				cout<<i<<" "<<j<<" "<<k<<":"<<ans[i][j][k]<<endl;
			}
	cout<<ans[as][bs][cs]<<endl;

}

