/*Problem to solve:
    https://leetcode.com/problems/sort-the-jumbled-numbers/description/
    You are given a vector/array of integers
    You need to swap each digit in each integer with the integer matching mapping[index]
    Then sort based on the new numbers, but the numbers should be the original ones
    E.g. With mapping = [8,9,4,0,2,1,3,5,7,6], 123 becomes 940 as mapping[1]->9, mapping[2]->4, mapping[3]->0
*/
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }

        for (int i = 0; i < temp.size(); i++) {
            string str = to_string(temp[i]);
            int tempVal = 0;
            for (int j = 0; j < str.size(); j++) {
                int value = mapping[str[j] - '0'];
                tempVal += value * pow(10, str.size() - j - 1);
            }
            temp[i] = tempVal;
        }

        vector<pair<int, int>> pairs;
        for (int i = 0; i < temp.size(); i++) {
            pairs.emplace_back(nums[i], temp[i]);
        }

        sort(pairs.begin(), pairs.end(), [&](const auto left, const auto right) {
            return left.second < right.second;
        });

        for (int i = 0; i < temp.size(); i++) {
            temp[i] = pairs[i].first;
        }

        return temp;
    }
};