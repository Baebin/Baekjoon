#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int kr, en, math;
};

bool cmp(const Student& a, const Student& b) {
    if (a.kr != b.kr)
        return a.kr > b.kr;
    if (a.en != b.en)
        return a.en < b.en;
    if (a.math != b.math)
        return a.math > b.math;

    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Student> vec;

    string name;
    int kr, en, math;
    for (int i = 0; i < N; i++) {
        cin >> name
            >> kr >> en >> math;

        vec.push_back({ name, kr, en, math });
    }

    sort(vec.begin(), vec.end(), cmp);
    for (Student student : vec)
        cout << student.name << "\n";
}