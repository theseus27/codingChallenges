//Testing
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    vector<int> problem = {3, 2, 4};
    vector<int> solution = twoSum(problem, 6);
    cout << solution[0] << " " << solution[1] << endl;

    return 0;
}

//Copy vector to set
set <int> s;
copy(nums.begin(), nums.end(), inserter(s, s.end()));

int idx = 0;
for (int x:nums) {
    if (s.find(target-x) != s.end()) {
        vector<int>iterator first = find(nums.begin(), nums.end(), x);
        vector<int>iterator second = find(nums.begin(), nums.end(), target-x);
        if (first != second) {
            result.push_back(first);
            result.push_back(second);
            return result;
        }
    }
    idx += 1
}
return result; 

//Iterators
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        int key = target-curr;
        auto itr = find(nums.cbegin(), nums.cend(), key);
        if (itr != nums.cend()) {
            result.push_back(i);
            result.push_back(distance(nums.cbegin(), itr));
            return result;
        }
    }
    return result;
}

//Copy to new vector
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>copy = nums;
    vector<int>solution;
    sort(copy.begin(), copy.end());
    
    //Find index where number is > target/2
    int midpoint = 0;
    for (int i = nums.size(); i > 0; i--) {
        if (copy[i] > target/2) {
            midpoint = i;
        }
    }
    
    //Look for matching numbers to add
    for (int i = 0; i < midpoint; i++) {
        int match = target - copy[i];
        for (int j = i+1; j < nums.size(); j++) {
            if (copy[j] == match) {
                solution.push_back(copy[i]);
                solution.push_back(copy[j]);
            }
        }
    }
    
    //Index the two numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == solution[0] || nums[i] == solution[1]) {
            solution.push_back(i);
        }
    }
    
    //Clear the two values
    solution.erase(solution.begin(), solution.begin()+1);
    return solution;
}
