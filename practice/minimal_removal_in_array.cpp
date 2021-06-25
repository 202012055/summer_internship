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
	int a[] = {1, 3, 4, 9, 10,11, 12, 17, 20};
    	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	sort(begin(a),end(a));
	int i,j,ans=1;
	i=j=0;
	while(j<n){
		cout<<i<<":"<<j<<endl;
		if(a[j]-a[i]<=k){
			ans=max(ans,j-i+1);
			j++;
		}
		else i++;
	}
	cout<<n-ans<<endl;
}

