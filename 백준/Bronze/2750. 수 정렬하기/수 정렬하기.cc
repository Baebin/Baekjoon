#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec, const int& left, const int& right) {
    vector<int> tmp(vec.size());
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j])
            tmp[k++] = vec[i++];
        else tmp[k++] = vec[j++];
    }
    while (i <= mid)
        tmp[k++] = vec[i++];
    while (j <= right)
        tmp[k++] = vec[j++];
    for (int l = left; l <= right; l++)
        vec[l] = tmp[l];
}

void mergeSort(vector<int>& vec, const int& left, const int& right) {
    if (!(left < right))
        return;
    int mid = (left + right) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, right);
}

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    mergeSort(vec, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << vec[i] << '\n';
}