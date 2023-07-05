#include <bits/stdc++.h>
using namespace std;

#define MAX 101
int Map[MAX];
int team[MAX];
int visited[MAX];
priority_queue<int, vector<int>, greater<int>> pq;
int N, cnt;

void DFS(int here, int n)
{
    int next;
    if(visited[here] == -1 || team[here] == 1)
        return;
    
    if(visited[here] == 0){
        visited[here] = 1;
    }
    else if(visited[here] == 1){
        team[here] = 1;
        cnt++;
        pq.push(here);
        
    }
    
    next = Map[here];
    DFS(next, n);
    visited[here] = -1;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> Map[i];
    }

    for(int i = 1; i <= N; i++)
    {
        if(visited[i] != 0)
            continue;
        DFS(i, N);
    }

    cout << cnt << "\n";
    for(int i=0; i < cnt; i++){
        cout << pq.top() << "\n";
        pq.pop();
    }
}