#include <iostream>

using namespace std;

int n;
int arr[40000];
int lis[40000];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    lis[0] = arr[0];
    int len = 1;

    for (int i = 1; i < n; i++) {
        if (lis[len - 1] < arr[i]) {
            lis[len] = arr[i];
            len += 1;
            continue;
        }

        auto it = lower_bound(lis, lis + len, arr[i]);
        // cout << "it: " << *it << '\n';

        if (it == lis + len) {
            *it = arr[i];
            len += 1;
        } else {
            if (*it > arr[i]) {
                *it = arr[i];
            }
        }
    }

//     for (int i = 0; i < len; i++) {
//         cout << lis[i] << ' ';
//     }
//     cout << '\n';
    
    cout << len << '\n';
}
