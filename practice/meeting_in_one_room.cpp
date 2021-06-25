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
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n,s,f;
	cin>>n;
	vector<tuple<int,int,int>> v;
	FOR(i,n){
		cin>>s>>f;
		v.emplace_back(f,s,i+1);
	}
	sort(v.begin(),v.end());
	int mx=get<0>(v[0]);
	cout<<get<2>(v[0])<<" ";
	int i=1;
	while(i<n){
		if(get<1>(v[i])>mx){
			cout<<get<2>(v[i])<<" ";
			mx=get<0>(v[i]);
		}
		i++;
	}
	cout<<endl;

}

