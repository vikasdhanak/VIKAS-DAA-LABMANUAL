#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char arr[n];
    int count[256] = {0};

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i]]++;
    }

    int maxFreq = 0;
    char ans;

    for (int i = 0; i < 256; i++) {
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            ans = (char)i;
        }
    }

    cout << ans << " " << maxFreq;

    return 0;
}