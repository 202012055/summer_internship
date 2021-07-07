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
auto pairhasher=[](const pair<int,int>& p){return p.F+p.S;};
unordered_map<pair<int,int>,int,decltype(pairhasher)> ans(1000,pairhasher);
int *v,*w,c=0;
int sol(int n,int W){
	if(n==0 || W<1)return 0;
	if(ans.count(make_pair(n,W)))return ans[make_pair(n,W)];
	int a=sol(n-1,W);
	if(W>=w[n]){
		int b=sol(n-1,W-w[n])+v[n];
		if(a<b)a=b;
	}
	ans.insert(make_pair(make_pair(n,W),a));
	c++;
	return a;
	
}



void solve(){
	int n,W;
	cin>>n>>W;
	v=new int[n+1];
	w=new int[n+1];
	auto pairhasher=[](pair<int,int> p){return p.F+p.S;};
	FOR(i,1,n+1)cin>>v[i];
	FOR(i,1,n+1)cin>>w[i];
	ans.clear();
	cout<<sol(n,W)<<endl;
	cout<<c<<endl;
}

