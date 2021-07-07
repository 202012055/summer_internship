#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	string s,o;
	cin>>s;
	auto isvovel=[](char c){
		c=tolower(c);
		return 0!=strchr("aeiou",c);
	};
	for(auto c:s){
		if(!isvovel(c)){
			o.push_back('.');
			o.push_back(tolower(c));	
		}
	}
	cout<<o<<endl;

}

