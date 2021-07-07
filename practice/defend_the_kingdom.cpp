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
	//cin>>t;
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	//w->x
	int w,h,n;
	cin>>w>>h>>n;
	if(n==0){cout<<w*h<<endl;return;}
	int x[n],y[n];
	FOR(i,n)cin>>x[i]>>y[i];
	sort(x,x+n);
	sort(y,y+n);
	int xm=max(x[0]-1,w-x[n-1]);
	int ym=max(y[0]-1,h-y[n-1]);
	for(int i=0;i<n-1;i++){
		xm=max(xm,x[i+1]-x[i]-1);
		ym=max(ym,y[i+1]-y[i]-1);
	}
	cout<<xm*ym<<endl;

}

