#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'

//#define DEBUG
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

//air=0 water=1 fire=2
typedef tuple<int,int,int> triple;
auto hasher=[](const triple&t){ return get<0>(t)^get<1>(t)^get<2>(t);};
unordered_map<triple,pair<int,string>,decltype(hasher)> cache(1000,hasher);
pair<int,string> air(int H,int A);
pair<int,string> water(int H,int A);
pair<int,string> fire(int H,int A);
pair<int,string> air(int H,int A){
	D("air",H,A,endl);
	try{
		return cache.at(make_tuple(0,H,A));
	}catch(out_of_range& o){
		auto w=water(H-5,A-10);
		auto f=fire(H-20,A+5);
		auto tmp=max(w,f);
		cache[make_tuple(0,H,A)]=make_pair(tmp.F+1,tmp.S+'a');
		return make_pair(tmp.F+1,tmp.S+'a');
	}
}
pair<int,string> water(int H,int A){
	D("water",H,A,endl);
	if(H<1 || A<1)return make_pair(0,"");
	try{
		return cache.at(make_tuple(1,H,A));
	}catch(out_of_range& o){
	D("R-water",H,A,endl);
		auto a=air(H+3,A+2);
		cache[make_tuple(2,H,A)]=make_pair(a.F+1,a.S+'w');
		return make_pair(a.F+1,a.S+'w');
	}
}
pair<int,string> fire(int H,int A){
	D("fire",H,A,endl);
	if(H<1 || A<1)return make_pair(0,"");
	try{
		return cache.at(make_tuple(2,H,A));
	}catch(out_of_range& o){
		auto a=air(H+3,A+2);
		cache[make_tuple(2,H,A)]=make_pair(a.F+1,a.S+'f');
		return make_pair(a.F+1,a.S+'f');
	}
}
void solve(){
	int H,A;
	cin>>H>>A;
	cache.clear();
	auto mx=max({air(H+3,A+2),water(H-5,A-10),fire(H-20,A+5)});
	cout<<mx.F<<endl;
	cout<<mx.S<<endl;
	auto cp=mx.S.rbegin();
	cout<<H<<":"<<A<<"|"<<H*100/A<<endl;
	while(cp!=mx.S.rend()){
		cout<<(*cp)<<endl;
		switch(*cp){
			case 'a':H+=3;A+=2;
				break;
			case 'w':H-=5;A-=10;
				break;
			case 'f':H-=20;A+=5;
				 break;
		}
	cout<<H<<":"<<A<<"|"<<H*100/A<<endl;
		cp++;
	}

}

