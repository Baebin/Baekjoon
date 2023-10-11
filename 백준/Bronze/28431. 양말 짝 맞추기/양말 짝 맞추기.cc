#include <iostream>
#include <map>
using namespace std;

int main(void){
    map<int, int> m;

    for (int i = 0; i < 5; i++) {
        int N;
        cin >> N;
        m[N]++;
    }
    for (auto element : m)
        if (element.second % 2 == 1)
            cout << element.first;
}