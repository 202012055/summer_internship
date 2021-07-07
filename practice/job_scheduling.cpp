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
	cin>>t;
	while(t--){
		D("TEST:",t+1,endl);
		solve();
	}
	return 0;
}

struct Job{int dead,profit;};

void solve(){
	int a,b,n;
	cin>>n;
	vector<Job> js;
	int mdead=0;
	FOR(i,n){
		cin>>a>>b;js.push_back(Job{a,b});
		mdead=max(mdead,i);
	}
	bool filled[mdead+1]{};
	sort(js.begin(),js.end(),[](Job&o,Job&p){return (o.profit>p.profit);});
	FOR(i,n)D(js[i].dead,":",js[i].profit,endl);
	int cnt=0,tot=0;
	FOR(i,n){
		int curr=js[i].dead;
		while(curr!=0&&filled[curr])curr--;
		if(curr){
			cnt++;
			tot+=js[i].profit;
			filled[curr]=1;
		}
	}
	cout<<cnt<<" "<<tot<<endl;
		

}

