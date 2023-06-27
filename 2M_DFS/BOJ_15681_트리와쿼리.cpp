#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

vector<int> tree[MAX];
bool visited[MAX] = {false,};
int ans[MAX];
int N, R, Q, U, V;

int DFS (int node)
{
    visited[node] = true;
    int cnt = 1;
    for(int i = 0; i < tree[node].size(); i++) {
        if(visited[tree[node][i]]) continue;
        cnt += DFS(tree[node][i]);
    }
    ans[node] = cnt;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    for(int i = 0; i < N-1; i++)
    {
        cin >> U >> V;

        tree[U].push_back(V);
        tree[V].push_back(U);
    }
    ans[R] = DFS(R);
    for(int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << ans[q] << "\n";
    }
}