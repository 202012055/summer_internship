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
	//cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}
struct fople{int ai,aj,bi,bj;};
auto hasher=[](const fople& f){return f.ai^f.aj^f.bi^f.bj;};
unordered_map<fople,int,decltype(hasher)> sm(1000,hasher);
fople ans{-1,-1,-1,-1};
int get_sum(const fople& f){
	D("get_sum:",f.ai,f.aj,f.bi,f.bj,endl);
}
void solve(){
	int r,c;
	cin>>r>>c;
	int v[r][c];
	FOR(i,r){
		FOR(j,c){
			cin>>v[i][j];
		}
	}
	get_sum(fople{0,0,r,c});




}

