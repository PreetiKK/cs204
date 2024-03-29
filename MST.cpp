
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

int findset(int a,int ds[],int rank[])
{
    if(a==ds[a]) return a;
    ds[a]=findset(ds[a],ds,rank);
    return ds[a];
}

int dsu(int a, int b,int ds[],int rank[])
{
     
    int repa=findset(a,ds,rank);
    int repb=findset(b,ds,rank);
    if(rank[repa]==rank[repb])
    {
        rank[repb]++;
        ds[repa]=repb; 
    }
    if(rank[repa]>rank[repb])
    {
        ds[repb]=repa; 
    }
    else 
    {
        ds[repa]=repb; 
    }
    return 1;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pii>> v;

    forr(i,0,m-1)
    {
        int a,b,c;
        cin>>c>>b>>a;
        v.pb({c,{a,b}});

    }
    sort(v.begin(),v.end()); //first we have to take min edge 


    int ds[n];
    int rank[n];
    forr(i,0,n-1)
    {
        ds[i]=i;//rep makesets
        rank[i]=0;
    }

    int sum=0;

    forr(i,0,m-1)
    {
        int a=v[i].second.first;
        int b=v[i].second.second;
        if(findset(a,ds,rank)!=findset(b,ds,rank)) //not in mst if findset is not same 
        {
            dsu(a,b,ds,rank);
            sum+=v[i].first;
        }
            
    }
    cout<<sum<<endl;
}
