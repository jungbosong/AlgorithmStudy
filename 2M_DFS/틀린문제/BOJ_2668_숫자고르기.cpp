#include <bits/stdc++.h>
using namespace std;

#define MAX 101
int Map[MAX];
bool visited[MAX] = {};
priority_queue<int> pq;
int N;

bool DFS(int root, int start, int end)
{
    cout << "DFS(" << root << ", " << start << ", " << end << "\n";
    if(visited[root] || visited[start] || visited[end]) return false;
    visited[root] = true;
    visited[start] = true;
    visited[end] = true;
    if(start == end || root == end) {
        pq.push(start);
        return true;
    }
    if(DFS(root, end, Map[end])) {
        pq.push(root);
    }
    return false;
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
        if(!visited[i]) DFS(i, i, Map[i]);
    }

    cout << pq.size() << "\n";
    while(!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
}