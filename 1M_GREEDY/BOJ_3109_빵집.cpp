#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[10001][501];
int dx[3] = {-1,0,1};
int dy[3] = {1,1,1};
bool Visit[10001][501];
int R,C;
bool check;
int ans = 0;

void DFS(int x, int y)
{
    Visit[x][y] = true;
    if (y == C - 1)
    {
        check = true;
        ans++;
        return;
    }
 
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && ny >= 0 && nx < R && ny < C)
        {
            if (board[nx][ny] == '.' && Visit[nx][ny] == false)
            {
                DFS(nx, ny);
                if (check == true) return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> R >> C;
    fill(&Visit[0][0], &Visit[R][C], false);

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        check  = false;
        DFS(i,0);
    }
    
    cout << ans;
}