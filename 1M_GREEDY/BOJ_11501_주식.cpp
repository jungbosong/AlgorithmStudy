#include <bits/stdc++.h>
using namespace std;

int data[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        queue<int> bought;
        int ans = 0;

        cin >> n;

        for(int i = 0; i < n; i++) cin >> data[i];

        for(int i = 0; i < n-1; i++) {
            if(data[i] <= data[i+1]) bought.push(data[i]);
            else {
                while(!bought.empty()) {
                    ans += data[i] - bought.front();
                    bought.pop();
                }
            }
        }

        while(!bought.empty()) {
            ans += data[n-1] - bought.front();
            bought.pop();
        }

        cout << ans << "\n";
    }

    return 0;
}