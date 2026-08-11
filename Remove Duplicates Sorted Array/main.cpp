#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int start = 0;
        int count = 1;
        int n = nums.size();

        if (n == 0) return 0;

        while (count < n) {

            if (nums[count] == nums[count - 1]) {
                count++;
                continue;
            }

            nums[start + 1] = nums[count];

            count++;
            start++;
        }

        return start + 1;
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

    int k = obj.removeDuplicates(nums);

    cout << "Unique elements: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    cout << "k = " << k << endl;

    return 0;
}