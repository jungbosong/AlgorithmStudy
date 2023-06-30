#include <bits/stdc++.h>
using namespace std;

#define MAX 101
int isOpened[MAX][MAX];
vector<int> erased;
vector<pair<int, int>> cheese;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N,M;
int cnt = 0;
int ans = 0;

void CheckOpened()
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 || i == N-1 || j == 0 || j == M-1) continue;
            if(isOpened[i][j] == 2 || isOpened[i][j] == 0) continue;
            bool check = false;
            for(int dr = 0; dr < 4; dr++) {
                int nx = i + dx[dr];
                int ny = j + dy[dr];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(isOpened[nx][ny] == 0) {
                    check = true;
                }
            }
            if(check) isOpened[i][j] = 0;
            else isOpened[i][j] = 1;
        }
    }
}

int RemoveCheese()
{
    int eraseCnt = 0;

    for(int i = 0; i < cheese.size(); i++)
    {
        int x = cheese[i].first;
        int y = cheese[i].second;
        int air = 0;
        if(erased[i])continue;
        for(int dr = 0; dr < 4; dr++) {
            int nx = x + dx[dr];
            int ny = y + dy[dr];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(isOpened[nx][ny] == 0) {
               air++; 
            }
        }
        if(air >= 2) {
            isOpened[x][y] = 3;
            erased[i] = true;
            eraseCnt++;
        }
    }
    return eraseCnt;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    fill(&isOpened[0][0], &isOpened[N][M], -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int value;
            cin >> value;
            if(i == 0 || i == N-1 || j == 0 || j == M-1) isOpened[i][j] = 0;
            if(value) {
                isOpened[i][j] = 2;
                cheese.push_back({i,j});
                erased.push_back(false);
            }
        }
    }
    cnt = cheese.size();

    while(true)
    {
        if(cnt <= 0) break;
    
        CheckOpened();
        cnt -= RemoveCheese();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(isOpened[i][j]==1 || isOpened[i][j] ==3) isOpened[i][j] = 0;
            }
        }
        ans++;
    }
    cout << ans;
}