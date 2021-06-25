#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
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
#include<iterator>

void solve(){
	int n;cin>>n;
	int v[7],ans[7];
	begin(v);
	FOR(i,0,n)cin>>v[i];
	FOR(i,0,n){
		int a=0;
		for(int j=0;j<i;j++){
			if(v[j]<v[i] && a<ans[j])a=ans[j];
		}
		ans[i]=a+v[i];
	}
	FOR(i,0,n)cout<<ans[i]<<endl;
	cout<<*max_element((ans),(&ans[0]+n))<<endl;

}

