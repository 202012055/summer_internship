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
	//cin>>t;
	FOR(i,t){
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}
bool next_permutation(char* s,char* e){
	char*c=e-1;
	if(s==c)return false;
	c--;
	while(c>=s){
		if(*c<*(c+1))break;
		c--;
	}
	if(c<s)return false;
	char*o=e-1;
	while(*c>=*o)o--;
	swap(*c,*o);
	reverse(c+1,e);
	return true;
	
}

void solve(){
	char a[]="dcab";
	do{
		cout<<a<<endl;
	}while(next_permutation(a,a+4));

}

