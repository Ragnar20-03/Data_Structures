#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int bioHazard(int n, vector<int> allergic, vector<int> poisonous) {
    // Step 1: Create the poisonous map
    unordered_map<int, unordered_set<int> > poisonous_map;
    int m = allergic.size();
    for (int i = 0; i < m; ++i) {
        poisonous_map[allergic[i]].insert(poisonous[i]);
    }

    // Step 2: Identify valid intervals
    int valid_intervals = 0;

    // Track the furthest point we can extend an interval starting at each position
    for (int start = 1; start <= n; ++start) {
        unordered_set<int> poisonous_to_current_interval;

        bool is_valid = true;
        for (int end = start; end <= n; ++end) {
            // Check if the current bacteria (end) is poisonous to any bacteria in the interval
            if (poisonous_to_current_interval.find(end) != poisonous_to_current_interval.end()) {
                is_valid = false;
                break;
            }

            // Add current bacteria's poisonous relationships to the set
            if (poisonous_map.find(end) != poisonous_map.end()) {
                for (int poisonous_bacteria : poisonous_map[end]) {
                    poisonous_to_current_interval.insert(poisonous_bacteria);
                }
            }

            if (is_valid) {
                valid_intervals++;
            }
        }
    }

    return valid_intervals;
}

int main() {
    int n = 3;
   vector<int> allergic ;
    allergic.push_back(1);
    allergic.push_back(2);
    // allergic.push_back(3);
    vector<int> poisonous;
    poisonous.push_back(3);
    poisonous.push_back(4);
    // poisonous.push_back(1);

    int result = bioHazard(4, allergic, poisonous);
    cout << "Number of valid intervals: " << result << endl;  // Output should be 4

    return 0;
}