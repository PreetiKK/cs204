#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef vector<pair<int,int>> vpii;
#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

ll frev(ll x,ll y)
{
	return x>y;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pii>> v;

	//  vector  array [n];
	ll d[n][n];
	forr(j,0,n-1)
	{
		forr(i,0,n-1)
		{
			if(j==i) d[j][i]=0;
			else
				d[j][i] = INT_MAX ;
		}
	}
	forr(i,0,m-1)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		v.pb({c,{a,b}});
		//array[b].push.back(a);
		d[a][b]=c;

	}
	
	
	forr(j,0,n-1)
	{
		forr(i,0,n-1)
		{
			if(d[j][i]==INT_MAX)
				cout<<"inf"<<" ";
			else
				cout<<d[j][i]<<" ";
		}
		cout<<"\n";
	}

	forr(k,0,n-1){
		forr(j,0,n-1){
			forr(i,0,n-1){

				if(d[j][i] > d[j][k] + d[k][i])
					d[j][i]=d[j][k] + d[k][i];
			}
		}
	}


}
