#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e;
    vector<pair<int, int>> lecture;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        lecture.push_back({e,s});
    }

    sort(lecture.begin(), lecture.end(),greater<>());
    int ans = 0;
    queue<int> q;
    while(lecture.size() != 0){
        int t = lecture[0].second;
        lecture.erase(lecture.begin() + 0);

        for(int i = 0; i < lecture.size(); i++) {
            if(lecture[i].first <= t) {
                t = lecture[i].second;
                q.push(i);
            }
        }
        int l = 0;
        while(!q.empty()) {
            lecture.erase(lecture.begin() + (q.front()-l)); 
            l++;
            q.pop();
        }
        ans++;
    }

    cout << ans;
}