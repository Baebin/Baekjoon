#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    // idx: 0 ~ (size - 1)
public:
    void add(const int& value) {
        heap.push_back(value);

        int parent;
        int child = heap.size() - 1;
        while (child > 0 && heap[parent = (child - 1) / 2] < heap[child]) {
            swap(heap[child], heap[parent]);
            child = parent;
        }
    }

    int pop() {
        // Empty
        if (heap.size() == 0) return 0;

        int item = heap[0];
        int last = heap.back();
        heap.pop_back();

        int parent = 0, child = 1;

        int size = heap.size();
        while (child < size) {
            if (child < size - 1 && (heap[child] < heap[child + 1]))
                child++;
            if (last >= heap[child])
                break;

            heap[parent] = heap[child];
            parent = child;

            child = (child * 2) + 1;
        }

        // Not Empty
        if (size > 0)
            heap[parent] = last;

        return item;
    }
private:
    vector<int> heap;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MaxHeap heap;

    int N;
    cin >> N;

    // Save
    vector<int> vec(N);

    int num;
    while (N--) {
        cin >> num;

        if (num == 0) cout << heap.pop() << "\n";
        else heap.add(num);
    }
}