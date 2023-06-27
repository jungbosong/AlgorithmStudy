#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
pair<int,int> p[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> p[i].X >> p[i].Y;

    sort(p,p+n);

    priority_queue<pair<int,int>> pq;
    pq.push(p[0]);
    

    for(int i = 1; i < n; i++) {
        pair<int,int> check = pq.top();
        if(check.X <= p[i].X && p[i].X <= check.Y && check.Y < p[i].Y) {
            pq.pop();
            pq.push({check.X, p[i].Y});
        }
        else if(check.Y < p[i].X) pq.push(p[i]);
    }

    long long sum = 0;
    while(!pq.empty()){
        sum += pq.top().Y - pq.top().X;
        pq.pop();
    }

    cout << sum;
}