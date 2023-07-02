#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(C);

    if(A==B) {
        if(A<C) pq.push(C-A); 
    }
    else if(A==C){
        if(B<A) pq.push(C-B);
    }
    else if(A<B) { 
        if(B==C){
            pq.push(C-A);
            pq.push(C-B);
        }
        else if(B<C) {
            pq.push(C-A);
            pq.push(C-B);
            pq.push(B);
        }
        else if(A<C && C<B) pq.push(C-A);
    }
    else if(A>B) {
        if(C>A) pq.push(C-B); 
    }

    int cnt = pq.size();
    for(int i = 0; i < cnt; i++) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}