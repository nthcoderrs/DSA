// 1 based indexing
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {

            int sum = numbers[i] + numbers[j];

            if (sum == target) {
                return {i + 1, j + 1};
            }
            else if (sum > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return {};
    }
};

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter sorted numbers: ";

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<int> answer = obj.twoSum(numbers, target);

    if (!answer.empty()) {
        cout << "Indices: "
             << answer[0] << " "
             << answer[1] << endl;
    }
    else {
        cout << "No pair found." << endl;
    }

    return 0;
}