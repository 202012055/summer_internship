#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,b,e) for(int (i)=(b);(i)<(e);(i)++)

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

void solve(){
	string s;cin>>s;
	int l=s.size();
	int a[l],p,t;
	for(int i=0;i<l;i++)a[i]=1;
	for(int i=l-2;i>=0;i--){
		p=0;
		for(int j=i+1;j<l;j++){
			t=a[j];
			if(s[i]==s[j])a[j]=p+2;
			else a[j]=max(a[j],a[j-1]);
			cout<<a[j]<<" ";
			p=t;
		}
		cout<<endl;
	}
	cout<<a[l-1]<<endl;

}

