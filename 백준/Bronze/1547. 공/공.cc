#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec{ 1, 2, 3 };
    
    int M;
    cin >> M;
    while (M--) {
        int A, B;
        cin >> A >> B;
        int tmp = vec[A - 1];
        vec[A - 1] = vec[B - 1];
        vec[B - 1] = tmp;
    }
    for (int i = 0; i < 3; i++)
        if (vec[i] == 1)
            cout << (i + 1) << '\n';
}