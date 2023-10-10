#include <iostream>
using namespace std;

int main() {
    int N, U, L;
    cin >> N >> U >> L;
    
    bool boj = (N >= 1000);
    bool ms = (U >= 8000) | (L >= 260);
    if (boj && ms)
        cout << "Very Good";
    else if (boj && !ms)
        cout << "Good";
    else cout << "Bad";
}