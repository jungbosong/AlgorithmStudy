#include <bits/stdc++.h>
using namespace std;

// flowers는 n번째 꽃의 (지는날(달,월), 피는날(달,월))
// x는 피는날(달,일), 지는날(달,일)
pair<pair<int,int>, pair<int,int>> flowers[100001], x;
pair<int, int> t;
int n;
int ans = 0;

void SetEndDay(int i) {
    int em = flowers[i].first.first;
    int ed = flowers[i].first.second;
    if(ed == 1) {
        if (em == 1) {
            flowers[i].first.first = 12;
            flowers[i].first.second = 31;
            return;
        }
        else if(em == 5 || em == 7 || em == 10 || em == 12) {
            flowers[i].first.second = 30;
        } else if (em == 3) {
            flowers[i].first.second = 28;
        } else{
            flowers[i].first.second = 31;
        }
        flowers[i].first.first--;
        return;
    } else {
        flowers[i].first.second--;
        return;
    }
}

int getAnswer() {
    if(flowers[0].second.first >= 3 && flowers[0].second.second >= 1) {
        return 0;
    }
    t.first = 3; t.second = 1; // t 초기화
    x.first.first = flowers[0].second.first; x.first.second = flowers[0].second.second; // x의 피는 날
    x.second.first = flowers[0].first.first; x.second.second = flowers[0].first.second; // x의 지는 날
    
    // x초기화 (x의 시작날 < t)
    int idx = 0;
    while(0) {
        idx++;
        for(int i = idx; i < n; i++) {
            if(flowers[i].second.first < t.first) {
                if(flowers[i].second.first < x.second.first) {
                    x.second.first = flowers[i].first.first;
                    if(flowers[i].first.second > x.second.second) x.second.second = flowers[i].first.second;
                    x.first.first = flowers[i].second.first; x.first.second = flowers[i].second.second;
                    t.first = x.first.first; t.second = x.first.second;
                    ans++;
                }
                else if(flowers[i].second.first == x.second.first) {
                    if(flowers[i].second.second <=  x.second.second) {
                        x.second.first = flowers[i].first.first;
                        if(flowers[i].first.second > x.second.second) x.second.second = flowers[i].first.second;
                        x.first.first = flowers[i].second.first; x.first.second = flowers[i].second.second; 
                        t.first = x.first.first; t.second = x.first.second;
                        ans++;
                    }
                }
            }
        }
        if(t.first > 11) break;
        if(t.first == 11 && t.second == 30)break;
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;

        flowers[i].first.first = em;
        flowers[i].first.second = ed;
        flowers[i].second.first = sm;
        flowers[i].second.second = sd;

        SetEndDay(i);        
    }

    sort(flowers, flowers+n);

    cout << getAnswer();

    return 0;
}