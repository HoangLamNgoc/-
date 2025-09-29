#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a[100000+5],v,ans;
int path[100000+5];
bool visited[100000+5];
int n,m,minval=0;
void inp(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    v.assign(n+1,-1);
    memset(path,-1,100000+5);
    fill_n(visited,n+1,false);
}
void bfs(int x){
    v[x]=0;
    queue<int>q;
    q.push(x);
    visited[x]=true;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (auto y:a[u]){
            if (!visited[y]){
                v[y]=v[u]+1;
                path[y]=u;
                visited[y]=true;
                q.push(y);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    inp();
    bfs(1);
    /*for (int i=2;i<=n;++i){
        cout<<v[i]<<" ";
    }*/
    cout<<v[n];
    for (int i=n;i!=-1;i=path[n]){
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    for (auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
