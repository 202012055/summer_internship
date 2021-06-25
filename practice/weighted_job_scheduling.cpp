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
	typedef tuple<int,int,int> triple;
	vector<triple> v;
	int s,f,p;
	v.emplace_back(-1,-1,0);
	FOR(i,0,n){
		cin>>s>>f>>p;
		v.emplace_back(s,f,p);
	}
	sort(v.begin(),v.end(),[](triple &a,triple &b){return get<1>(a)<get<1>(b);});
	int val[n+1];
	val[0]=0;
	for(int i=1;i<=n;i++){
		cout<<get<0>(v[i])<<" "<<get<1>(v[i])<<" "<<get<2>(v[i])<<endl;
		int j=upper_bound(v.begin(),v.begin()+i,v[i],[](const triple&a,const triple&b){return get<0>(a)<get<1>(b);})-1-v.begin();
		cout<<j<<endl;
		val[i]=max(val[i-1],val[j]+get<2>(v[i]));
		cout<<val[i]<<endl;
	}
	cout<<val[n]<<endl;

	

}

