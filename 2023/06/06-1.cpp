#include <iostream>

using namespace std;

int main() {
    unsigned long long time = 46689866;
    unsigned long long record = 358105418071080;

    unsigned long long result = 0;

    for (unsigned long long i = 10; i < time - 10; i++) {
        unsigned long long remainingTime = time - i;
        if (i * remainingTime >= record) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}