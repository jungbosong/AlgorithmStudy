#include<bits/stdc++.h>
using namespace std;

#define MAX 500
 
int MAP[MAX][MAX];
int DP[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M, Answer;
 
int DFS(int x, int y)
{
    if (x == N - 1 && y == M - 1) return 1;
    if (DP[x][y] != -1) return DP[x][y];
 
    DP[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            if (MAP[nx][ny] < MAP[x][y])
            {
                DP[x][y] = DP[x][y] + DFS(nx, ny);
            }
        }
    }
    return DP[x][y];
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            DP[i][j] = -1;
        }
    }

    cout <<  DFS(0, 0);
 
    return 0;
}