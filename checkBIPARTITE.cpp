#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long li;
#define forz(i,n) for(long i=0;i<n;i++)

bool BFS(vector<pair<int,int>> adl[],int i, vector<int> &vis){
adl[1][0].second = 1;
queue<pair<int,int>> q;
q.push(adl[1][0]);
while(!q.empty()){
   pair<int,int> temp = q.front();
q.pop();
vis[temp.first] = 1;

for(pair<int,int> &x:adl[temp.first]){
  vis[x.first] = 1;
  if(x.second == 0){
  if(temp.second == 1){
    x.second == 2;

}else{
    x.second = 1;
}
q.push(x);
}else{
  if(x.second == temp.second ){
     return false;

}
}
}
}
return true;
}


int main(){
  li n,m;
cin >>n>>m;
vector<pair<int,int>>adl[n+1];
vector<int> vis(n+1,0);
int u,v;
forz(i,n){
     if(vis[i+1] == 0){
   bool ans = BFS(adl,1,vis);
if(!ans){
  res = false;
}

}
}
if(res){
  cout <<"YES\n";
}else{
  cout<<"NO\n";
}
  return 0;
}
