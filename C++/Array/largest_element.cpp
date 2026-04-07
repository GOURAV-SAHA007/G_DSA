#include <bits/stdc++.h>
using namespace std;

void largest_fxn(const vector<int>& arr){
    int n = arr.size();
    int largest = arr[0];
    int second_largest = INT_MIN;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > largest) {
            second_largest = largest; // keep previous largest as second
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
    }
    cout << "largest element: " << largest << '\n';
    if (second_largest == INT_MIN)
        cout << "second largest: Not found" << '\n';
    else
        cout << "second largest: " << second_largest << '\n';
}

void smallest_fxn(const vector<int>& arr){
    int n = arr.size();
    int smallest = arr[0];
    int second_smallest = INT_MAX;

    for (int i = 1; i < n; ++i) {
        if (arr[i] < smallest) {
            second_smallest = smallest; // previous smallest becomes second
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
    }
    cout << "smallest element: " << smallest << '\n';
    if (second_smallest == INT_MAX)
        cout << "second smallest: Not found" << '\n';
    else
        cout << "second smallest: " << second_smallest << '\n';
}

int main(){
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (n <= 0) return 0;
    largest_fxn(arr);
    smallest_fxn(arr);

    return 0;
}