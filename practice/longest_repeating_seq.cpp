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
	string str;
	cin>>str;
	int m=str.size();
	    int ans[m+1][m+1];
	    for(int i=0;i<=m;i++)ans[0][i]=0;
	    for(int i=0;i<=m;i++)ans[i][0]=0;
	    for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
		    ans[i][j]=max({
			ans[i-1][j],
			ans[i][j-1],
			ans[i-1][j-1]+(i!=j&&str[i]==str[j]?1:0)
		    });
		}
	    }
	    cout<<ans[m][m]<<endl;
}

