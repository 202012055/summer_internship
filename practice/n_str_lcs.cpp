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
vector<string>matches;
void find_match(int *data,int width,int i,int j,string ans,string &a,string &b){
	for(int i=0;i<3;i++){
		for(int j=0;j<width;j++){
			cout<<(width*i+j)<<","<<data[width*i+j]<<" ";
		}
		cout<<endl;
	}
	cout<<i<<":"<<j<<":"<<ans<<endl;
	if(i==0 || j==0){
		reverse(ans.begin(),ans.end());
		matches.push_back(ans);
		return;
	}
	if(a[i-1]==b[j-1]){
		find_match(data,width,i-1,j-1,ans+a[i],a,b);
	}else{

		cout<<data[width*j+i]<<","<<data[width*j+i-1]<<endl;
		if(data[width*j+i]==data[width*j+i-1]) find_match(data,width,i-1,j,ans,a,b);
		if(data[width*j+i]==data[width*(j-1)+i]) find_match(data,width,i,j-1,ans,a,b);
	}
}
void lcs(string a,string b){
	int as=a.size();
	int bs=b.size();
	int mat[as+1][bs+1];
	for(int i=1;i<=as;i++){
		mat[0][i]=0;
	}
	for(int i=1;i<=bs;i++){
		mat[i][0]=0;
	}
	mat[0][0]=0;
	for(int j=1;j<=bs;j++){
		for(int i=1;i<=as;i++){
			if(a[i-1]==b[j-1]){
				mat[i][j]=mat[i-1][j-1]+1;
			}else{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	int ai=as,bi=bs;
	matches.clear();
	find_match((int*)mat,as+1,as,bs,"",a,b);
	
}
void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a;
	for(int i=1;i<n;i++){
		cin>>b;
		lcs(a,b);
		cout<<"matches:";
		for(auto m:matches)cout<<m<<",";
		cout<<endl;
	}
	cout<<a<<":"<<a.size()<<endl;

}

