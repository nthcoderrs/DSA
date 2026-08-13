#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            int sum = -nums[i];

            // Two Sum for each fixed i
            while (left < right) {

                int target = nums[left] + nums[right];

                if (sum == target) {

                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }

                }
                else if (sum > target) {
                    // Need a bigger target
                    left++;
                }
                else {
                    // Need a smaller target
                    right--;
                }
            }
        }

        return result;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1) excluding output space


int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution obj;

    vector<vector<int>> result = obj.threeSum(nums);

    for (auto triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}