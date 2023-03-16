#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

class PageCounter {
public:
    explicit PageCounter(const int &n) : N(n) {}
    vector<int> get() {
        vector<int> cnts(10);

        int left = 1, right = N;
        int weight_ten = 1;
        while (left <= right) {
            // Make the last digit of $left 0
            while (left % 10 != 0 && left <= right)
                add(left++, cnts, weight_ten);

            // Out of Range
            if (!(left <= right))
                break;

            // Make the last digit of $right 9
            while (right % 10 != 9 && left <= right)
                add(right--, cnts, weight_ten);

            // Number of last digits between $left and $right: (($right - $left) + 1)
            left /= 10, right /= 10;
            for (int i = 0; i <= 9; i++)
                cnts[i] += ((right - left) + 1) * weight_ten;
            weight_ten *= 10;
        }
        return cnts;
    }
protected:
    void add(int N, vector<int> &cnts, const int &weight_ten) {
        do cnts[N % 10] += weight_ten;
        while (N /= 10);
    }
private:
    int N;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    auto cnts = PageCounter(N).get();
    for (int cnt : cnts)
        cout << cnt << " ";
}