#include <bits/stdc++.h>
using namespace std;

#define MAX 300
#define X first
#define Y second

bool isIceberg[MAX][MAX];
int icebergMap[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
int N, M;
int Min = 10;
vector<pair<int,int>> V;
int ans = 0;

void After1Year()
{
    queue<int> Q;
    for(int i = 0; i < V.size(); i++) {
        for(int dr = 0; dr < 4; dr++) {
            int nx = V[i].X + dx[dr];
            int ny = V[i].Y + dy[dr];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(isIceberg[nx][ny]) break;
            if(--icebergMap[V[i].X][V[i].Y] == 0) {
                isIceberg[V[i].X][V[i].Y] = false;
                Q.push(i);
            }
        }
    }
    while(!Q.empty()) {
        V.erase(V.begin() + Q.front());
        Q.pop();
    }
}

void DFS(int x, int y)
{
    stack<pair<int,int>> s;
    s.push({x, y});
    visited[x][y] = true;

    while (!s.empty())
    {
        pair<int,int> cur = s.top(); s.pop();

        for(int dr = 0; dr < 4; dr++) {
            int nx = cur.X + dx[dr];
            int ny = cur.Y + dy[dr];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!isIceberg[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            s.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    fill(&visited[0][0], &visited[N][M], false);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> icebergMap[i][j];
            if(icebergMap[i][j] == 0) isIceberg[i][j] = false;
            else{
                if(icebergMap[i][j] < Min) Min = icebergMap[i][j];
                isIceberg[i][j] = true;
                V.push_back({i,j});
            } 
        }
    }
    for(int i = 0; i < Min; i++)
    {
        After1Year();
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            if(isIceberg[i][j] && !visited[i][j]){
                DFS(i,j);
                ans++;
            }
        }
    }

    if(ans > 0) cout << Min;
    else cout << 0;
}