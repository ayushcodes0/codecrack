//Write your code here
//Code by Jagpreet153
// Approach stored the duration and deadline in a map and then iterated over the map and calculated the reward for each task and added it to the ans variable and then printed the ans variable.
#include<bits/stdc++.h>
using namespace std;
long long int taskScheduling(vector<pair<long long int, long long int>>& tasks) {
    // Sort tasks based on durations in ascending order
    sort(tasks.begin(), tasks.end(), [](const pair<long long int, long long int>& a, const pair<long long int, long long int>& b) {
        return a.first<b.first;
    });
    long long int completionTime=0;
    long long int totalReward=0;
    for (const auto& task:tasks) {
        long long int duration = task.first;
        long long int deadline = task.second;
        // Calculate completion time
        completionTime += duration;
        // Calculate reward
        long long int reward = deadline - completionTime;
        // Update total reward
        totalReward += reward;
    }
    return totalReward;
}

 int main() {
    long long int numTasks;
    cin >> numTasks; 
    vector<pair<long long int, long long int>> tasks;
    for (long long int i = 0; i < numTasks; ++i) {
        long long int duration, deadline;
        cin >> duration;
        cin >> deadline;
        tasks.push_back(make_pair(duration, deadline));
    }
    long long int maxReward = taskScheduling(tasks);
    cout<<maxReward<<endl;
    return 0;
}
