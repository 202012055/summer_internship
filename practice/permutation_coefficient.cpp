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
	int n,r;
	cin>>n>>r;
	int mat[r+1]{};
	mat[0]=1;
	FOR(i,1,n+1){
		for(int j=min(i,r);j>0;j--){
			mat[j]+=(mat[j-1]*j);
		}
		FOR(j,0,min(i,r)+1)cout<<mat[j]<<" ";
		cout<<endl;
	}
	cout<<mat[r]<<endl;

}

