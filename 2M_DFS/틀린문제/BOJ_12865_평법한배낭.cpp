#include <bits/stdc++.h>
using namespace std;

#define W first
#define V second

vector<pair<int,int>> objects;
int maxV = 0;
int N, K;

void DFS(int idx, int bagW, int bagV)
{
    if(idx == N) return;
    bagW += objects[idx].W;
    if(bagW <= K) {
        bagV += objects[idx].V;
        DFS(++idx, bagW, bagV);
    }
    else{
        if(bagV > maxV)  maxV = bagV;
        DFS(++idx, 0, 0);
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        objects.push_back({w,v});
    }

    sort(objects.begin(), objects.end());

    DFS(0, 0, 0);
    cout << maxV;
}