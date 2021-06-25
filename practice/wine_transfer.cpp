#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'

#define DEBUG
#ifdef DEBUG
void _debug_print(){} //single arg
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<' '<<t;_debug_print(ts...);} //multi arg
#	define D(args...) _debug_print(args)
#else
#	define D(args...) 0
#endif

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n;cin>>n;
	int v[n];
	FOR(i,n)cin>>v[i];
	int i=0,j=0,a=0;
	while(i<n&&j<n){
		while(v[i]<1 && i<n)i++;
		while(v[j]>-1 && j<n)j++;
		if(i==n||j==n)break;
		D(i,j,endl);
		D(v[i],v[j],endl);
		if(v[i]<-v[j]){
			a+=abs(i-j)*v[i];
			v[j]+=v[i];
			v[i]=0;
		}else{
			a+=abs(i-j)*(-v[j]);
			v[i]+=v[j];
			v[j]=0;
		}
	}
	cout<<a<<endl;

}

