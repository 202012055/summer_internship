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
	ll ans[n+1];
	ans[0]=1;
	FOR(i,1,n+1){
		ll tmp=0;
		FOR(j,0,i){
			tmp+=ans[j]*ans[i-j-1];
		}
		ans[i]=tmp;
		cout<<i<<":"<<tmp<<endl;

	}

}

