#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& dop, int n) {
    int left = 0;
    int right = dop.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dop[mid] < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int Be(const std::vector<int>& val) {
    std::vector<int> dop;
    for (int num : val) {
        int ind = binarySearch(dop, num);
        if (ind == dop.size()) {
            dop.push_back(num);
        } else {
            dop[ind] = num;
        }
    }

    return dop.size();
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> val(n);
    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }

    int res = Be(val);
    std::cout<<res;
}
