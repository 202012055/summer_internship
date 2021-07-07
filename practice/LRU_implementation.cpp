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
	int n,m;
	cin>>n;
	int p[n];
	FOR(i,n)cin>>p[i];
	cin>>m;
	list<int> lru;
	unordered_map<int,decltype(lru.begin())> cache;
	int a=0;
	FOR(i,n){
		if(0==cache.count(p[i])){
			a++;
			if(m==lru.size()){
				int last=lru.front();
				lru.pop_front();
				cache.erase(last);
			}
			lru.push_back(p[i]);
			auto tmp=lru.end();
			tmp--;
			cache[p[i]]=tmp;
			
		}else{
			auto curr=cache[p[i]];
			lru.erase(curr);
			lru.push_back(p[i]);
			auto tmp=lru.end();
			tmp--;
			cache[p[i]]=tmp;
		}
	}
	cout<<a<<endl;

}

