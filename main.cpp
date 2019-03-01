#include <bits/stdc++.h>
using namespace std;
#define maxx 100002
vector <int> ShortestPathTree (vector < vector <int> > &V , int from ,int to,vector <int > &source )
{
    vector < int > distances(V.size());
    fill (distances.begin(),distances.end(),maxx);
    queue <int> Q;
    source [from] =  NULL;
    Q.push(from);
    distances[from]  =  0;
    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        for(int i=0;i<V[curr].size();i++)
        {
            if(distances [V[curr][i]] > distances[curr]+1){
            Q.push(V[curr][i]);
            distances [V[curr][i]] = min(distances [V[curr][i]] , distances[curr]+1);
            source [V[curr][i]] = curr;
            }
        }
    }
    return distances;

}


main()
{
    int n,m,x,y;
    cin >> n >> m;
    vector < vector <int> > V(n+1);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y ;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    vector <int> sources(V.size());
    cin >> x >> y;
    vector <int>distances = ShortestPathTree(V,x,y,sources);
    cout << ((distances[y]==maxx)?(-1):(distances[y]));




}
