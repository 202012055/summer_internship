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
	int r,c;
	cin>>r>>c;
	int v[r][c];
	FOR(i,0,r)
		FOR(j,0,c){
			cin>>v[i][j];
		}
	for(int cc=c-2;cc>=0;cc--){
		for(int rc=0;rc<r;rc++){
			v[rc][cc]+=max({
					v[rc][cc+1],
					rc?v[rc-1][cc+1]:0,
					rc!=r-1?v[rc+1][cc+1]:0
					});
		}
	}
	int m=-1;
	FOR(i,0,r)m=(m<v[i][0])?v[i][0]:m;
	cout<<m<<endl;
}

