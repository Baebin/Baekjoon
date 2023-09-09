#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// Declaration
#define fori_reverse(y, x) for (register int i = (y - 1); i >= x; i--)

// Structure
typedef string bits;

class OctalConverter {
public:
    OctalConverter(const bits& binary) {
        this->binary = binary;
    }
    bits binaryToOctal() {
        ostringstream stream;
        stack<int> st;

        int cnt = 0, stack = 0;
        const int& len = binary.length();
        fori_reverse(len, 0) {
            const int& bit = binary[i];
            stack += (bit - '0') * (1 << cnt);
            if (++cnt != 3 && i) continue;
            st.push(stack);
            stack = cnt = 0;
        }
        while (!st.empty()) {
            stream << st.top();
            st.pop();
        }
        return stream.str();
    }
private:
    bits binary;
};

int main() {
    bits binary;
    cin >> binary;

    OctalConverter converter = OctalConverter(binary);
    cout << converter.binaryToOctal();
}