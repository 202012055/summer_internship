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
	//cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}

int getmax(int*t,int n){
	unordered_map<int,int> sums;
	sums[0]=-1;
	int s=0,a=0;
	for(int i=0;i<n;i++){
		s+=t[i];
		if(sums.count(s)){
			a=max(a,i-sums[s]);	
		}else{
			sums[s]=i;
		}
	}
	D("getmx:",a,endl);
	return a;
}
void solve(){
	int r,c;cin>>r>>c;
	int num[r][c],t[r],mx=0;
	FOR(i,r)FOR(j,c)cin>>num[i][j];
	for(int m=0;m<c;m++){
		memset(t,0,r*sizeof(int));
		for(int n=m;n<c;n++){
			D(m,n,endl);
			for(int k=0;k<r;k++){
				D(k,n,num[k][n],endl);
				t[k]+=num[k][n]?1:-1;
			}
			mx=max(mx,(n-m+1)*getmax(t,r));
			FOR(q,r)D(t[q]," ");D(endl);
		}
	}
	cout<<mx;
}

