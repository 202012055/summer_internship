#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define endl '\n'

#define DEBUG
#ifdef DEBUG
template <typename T> void _debug_print(T t){ cerr<<t; } //single arg
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<" ";_debug_print(ts...);} //multi arg
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
	while(t--){
		D("TEST:",t+1,endl);
		solve();
	}
	return 0;
}

int maxsum(int*t,int n){
	int l=0,m=0;
	for(int i=0;i<n;i++){
		if(l+t[i]<t[i])l=t[i];
		else l+=t[i];
		m=max(m,l);
	}
	D("maxsum:",m,endl);
	return m;
}
void solve(){
	int r,c;cin>>r>>c;
	int v[r][c],t[r],mx=0;
	FOR(i,r)FOR(j,c)cin>>v[i][j];
	for(int m=0;m<c;m++){
		memset(t,0,sizeof(int)*r);
		for(int n=m;n<c;n++){
			for(int k=0;k<r;k++){
				t[k]+=v[k][n];
			}
			mx=max(mx,maxsum(t,r));
		}
	}
	cout<<mx<<endl;
}

