#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec(3);
    for (int i = 0; i < 3; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    int a = vec[1] - vec[0], b = vec[2] - vec[1];
    if(a > b) cout << (vec[0] + b);
    else if (a == b) cout << (vec[2] + a);
    else cout << (vec[1] + a);
}