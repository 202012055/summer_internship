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
void _debug_print(){} 
void _debug_print(char c){ cerr<<c; if(c!='\n')cerr<<' '; }
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<' ';_debug_print(ts...);} //multi arg
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
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}

void solve(){
	int N,K,B,T;
	cin>>N>>K>>B>>T;
	D(N,K,B,T,endl);
	int init[N];
	FOR(i,N)cin>>init[i];
	int v[N];
	FOR(i,N)cin>>v[i];
	int loosers=0,winners=0,swap=0;
	for(int i=N-1;i>=0&&winners<K;i--){
		if(init[i]+v[i]*T>=B){
			winners++;
			swap+=loosers;
		}else{
			loosers++;
		}
	}
	if(winners!=K)cout<<"IMPOSSIBLE"<<endl;
	else cout<<swap<<endl;


}

