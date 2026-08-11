#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int length = nums.size();

        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < length; i++) {

            if (nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }

        // Case I - All Positive
        if (neg.size() == 0) {

            for (int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }

            return pos;
        }

        // Case II - All Negative
        if (pos.size() == 0) {

            for (int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }

            reverse(neg.begin(), neg.end());

            return neg;
        }

        // Case III - Positive + Negative
        int i = 0;
        int j = 0;

        int m = neg.size();
        int n = pos.size();

        vector<int> res(m + n);

        int id = 0;

        // Square Negative Numbers
        for (int i = 0; i < m; i++) {
            neg[i] = neg[i] * neg[i];
        }

        reverse(neg.begin(), neg.end());

        // Square Positive Numbers
        for (int i = 0; i < n; i++) {
            pos[i] = pos[i] * pos[i];
        }

        // Merge both sorted arrays
        while (i < m && j < n) {

            if (neg[i] < pos[j]) {
                res[id] = neg[i];
                id++;
                i++;
            }
            else {
                res[id] = pos[j];
                id++;
                j++;
            }
        }

        // Negative Array Remaining
        while (i < m) {
            res[id] = neg[i];
            id++;
            i++;
        }

        // Positive Array Remaining
        while (j < n) {
            res[id] = pos[j];
            id++;
            j++;
        }

        return res;
    }
};

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted numbers: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> result = obj.sortedSquares(nums);

    cout << "Sorted Squares: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}