#include <bits/stdc++.h>
using namespace std;

#define MAX 2001
#define X first
#define Y second
int people[MAX][MAX]{};
bool exist = false;
int N, M;

int DFS(int idx, int cnt)
{
    stack<int> S;
    S.push(idx);
    int visited[MAX] {false};
    visited[idx] = true;
    cnt++;

    while(!S.empty())
    {
        int start = S.top();
        S.pop();
        for(int i = 0; i <= M; i++)
        {
            if(people[start][i] == 0) continue;
            if(visited[i]) continue;
            if(people[start][i]) {
                S.push(i);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        people[a][b] = 1;
    }

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= M; j++) {
            if(exist) break;
            if(people[i][j]) {
                if(DFS(j,0) >= 2) exist = true;
            }
        }
    }
    

    if(exist) cout << 1;
    else cout << 0;
}