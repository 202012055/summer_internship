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
	int n;
	cin>>n;
	int d[n+1];
	FOR(i,0,n+1)cin>>d[i];
	int a[n][n];
	FOR(i,0,n)a[i][i]=0;
	FOR(l,2,n+1){
		FOR(i,0,n-l+1){
			int m=INT_MAX;
			FOR(j,0,l-1){
				m=min(m,a[i][i+j]+a[i+j+1][i+l-1]+(d[i]*d[i+l]*d[i+j+1]));
			}
			a[i][i+l-1]=m;
		}
	}	
	cout<<a[0][n-1]<<endl;

}

