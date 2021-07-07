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
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n,k;
	int v;
	cin>>n>>k;
	vector<pair<int,int>> p;
	FOR(i,n){cin>>v;p.emplace_back(v,i+1);}
	sort(p.begin(),p.end());
	int o=0;
	for(int i=0;i<n;i++){
		if(p[i].F*p[i].S<=k){
			o+=p[i].S;
			k-=p[i].F*p[i].S;
		}else{
			o+=k/p[i].F;
			break;
		}
	}
	cout<<o<<endl;

}

