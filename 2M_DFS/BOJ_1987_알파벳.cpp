#include <bits/stdc++.h>
using namespace std;

#define MAX 21
#define X first
#define Y second

char board[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[26];
int dif[MAX][MAX];
int R,C, ans;

void DFS(int x, int y)
{
    stack<pair<int,int>> S;
    S.push({x,y});
    dif[0][0] = 1;
    while(!S.empty()){
        pair<int,int> cur = S.top(); S.pop();
        visit[board[cur.X][cur.Y]-'A'] = true;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(visit[board[nx][ny]-'A']) continue;
            if(dif[nx][ny] > 0) continue;
            dif[nx][ny] += dif[cur.X][cur.Y]+1;
            S.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> R >> C;

    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            cin >> board[row][col];
        }
    }

    fill(&visit[0], &visit[26], false);
    fill(&dif[0][0], &dif[R][C], 0);

    DFS(0,0);

    int ans = 0;
    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            if(dif[row][col] > ans) ans = dif[row][col];
        }
    }
    cout << ans;
}