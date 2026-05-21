#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    sort(arr, arr + n);

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == key) {
            cout << "Pair Found: " << arr[i] << " " << arr[j];
            found = true;
            break;
        }
        else if (sum < key) {
            i++;
        }
        else {
            j--;
        }
    }

    if (!found) {
        cout << "No Pair Found";
    }

    return 0;
}