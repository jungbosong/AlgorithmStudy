#include <bits/stdc++.h>
using namespace std;

long long cards[1001];
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m;
    long long sum = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> cards[i];
        sum += cards[i];
    }
    
    while(m--) {
        sort(cards, cards+n);
        long long tmp = cards[0] + cards[1];
        cards[0] = tmp;
        cards[1] = tmp;
        sum += tmp;
    }
    cout << sum;
}