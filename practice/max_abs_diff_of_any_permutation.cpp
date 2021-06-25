#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define endl '\n'

//#define DEBUG
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
	int n;
	cin>>n;
	int v[n];
	FOR(i,n)cin>>v[i];
	sort(v,v+n);
	int a[n];
	for(int i=0;i<n/2;i++){
		a[i*2]=v[i];
		a[i*2+1]=v[n-i-1];
	}
	if(n%2){
		a[n-1]=v[n/2];
	}
	FOR(i,n)D(a[i]);
	D(endl);
	int sum=abs(a[0]-a[n-1]);
	for(int i=0;i<n-1;i++){
		sum+=abs(a[i]-a[i+1]);
	}
	cout<<sum<<endl;

}

