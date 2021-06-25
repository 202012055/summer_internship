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
		D("TEST:",t+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n,k;cin>>n>>k;
	int p[n+1];
	p[0]=INT_MAX;
	FOR(i,n)cin>>p[i+1];
	vector<pair<int,int>> u;
	for(int i=2;i<=n;i++){
		if(p[i-1]<p[i]){
			if(p[i-2]>p[i-1]){
				u.emplace_back(p[i-1],p[i]);
			}else{
				u.back().S=p[i];
			}
		}
	}
	for(auto c:u)D(c.F,c.S,endl);
	int N=u.size();
	int mn[N][N];
	for(int i=N-1;i>=0;i--){
		mn[i][i]=u[i].F;
		for(int j=i+1;j<N;j++){
			mn[i][j]=min(mn[i+1][j],mn[i][j-1]);
			D(mn[i][j]," ");
		}
		D(endl);
	}
	int mx[N][N];
	for(int i=N-1;i>=0;i--){
		mx[i][i]=u[i].S;
		for(int j=i+1;j<N;j++){
			mx[i][j]=max(mx[i+1][j],mx[i][j-1]);
			D(mx[i][j]," ");
		}
		D(endl);
	}
	int profit=0;
	FOR(i,N)profit+=u[i].S-u[i].F;
	list<pair<int,int>> lst;
	typedef pair<int,decltype(lst.begin())> ptype;
	auto pcmp=[](const ptype&a,const ptype&b){return a.F<b.F;};
	priority_queue<ptype,vector<ptype>,decltype(pcmp)> minloss(pcmp);
	pair<int,int> last=u.front();
	lst.push_back(u[0]);
	auto lptr=lst.begin();
	for(int i=1;i<N;i++){
		int diff=min({u[i-1].S-u[i-1].F,u[i].S-u[i].F,u[i-1].S-u[i].F});
		minloss.push(make_pair(diff,lptr));
		lst.push_back(u[i]);
		lptr=lst.end();
		lptr--;
	}
	D("yes",endl);
	for(auto l:lst)D(l.F,l.S,endl);
	while(minloss.size()){
		D(minloss.top().F,endl);
		minloss.pop();
	}
	while(N>k){
		auto tar=minloss.top();
		minloss.pop();
	}
	
	/*
	while(N>k){
	D("state:",endl);
	FOR(i,N)D(u[i].F,u[i].S,endl);
		int loss=INT_MAX;
		auto e=u.end();
		e--;
		auto ptr=u.begin();
		auto gold=u.begin();
		auto agold(gold);
		agold++;
		while(ptr!=e){
			auto a=*ptr;
			auto b=*(ptr+1);
			int diff=min({a.S-a.F,b.S-b.F,a.S-b.F});
			if(loss>diff){
				loss=diff;
				gold=ptr;
			}
			ptr++;
		}
		profit-=loss;
		agold=gold;
		agold++;
		D("choosen:",((*gold).F),((*gold).S),((*agold).F),((*agold).S),endl);
		(*gold).F=min(((*gold).F),((*agold).F));
		(*gold).S=max(((*gold).S),((*agold).S));
		u.erase(agold);
		N--;
	}
	D("state:",endl);
	FOR(i,k)D(u[i].F,u[i].S,endl);
	cout<<profit<<endl;
	*/

}

