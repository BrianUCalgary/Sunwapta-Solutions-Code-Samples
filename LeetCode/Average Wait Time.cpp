/*Problem to solve:
    https://leetcode.com/problems/average-waiting-time/description/
    You are given a vector of vector of integers
    The vector of integers have 2 integers, the first one representing when they arrive/order, 
    the second representing how long it takes to make the product
    You need to find the average time between when customers order and when they recieve the product
*/
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime = 0;
        double totalStart = 0;
        int curTime = 0;
        for (int i = 0; i < customers.size(); i++) {
            curTime = max(customers[i][0], curTime);
            totalStart += customers[i][0];
            curTime += customers[i][1];
            totalTime += curTime;
        }
        cout << totalTime << " " << totalStart;
        double n = customers.size();
        return (totalTime - totalStart) / n;
    }
};