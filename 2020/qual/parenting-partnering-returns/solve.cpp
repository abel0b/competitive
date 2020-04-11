
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

struct Activity {
    int id;
    int start_time;
    int end_time;
};

struct Problem {
    string digits;
    vector<Activity> activities;
    bool solve();
};

bool Problem::solve() {
    bool solved = true;

    int jamy_busy = -1;
    int cameron_busy = -1;
    bool impossible = false;
    vector<int> schedule(activities.size(), -1);

    vector<Activity> sorted_activities = activities;
    sort(sorted_activities.begin(), sorted_activities.end(), [](const Activity& a1, const Activity& a2) {
        return a1.start_time < a2.start_time;
    });

    for (int i=0; i<sorted_activities.size(); i++) {
        if (jamy_busy != -1 && sorted_activities[jamy_busy].end_time <= sorted_activities[i].start_time) {
            jamy_busy = -1;
        }
        if (cameron_busy != -1 && sorted_activities[cameron_busy].end_time <= sorted_activities[i].start_time) {
            cameron_busy = -1;
        }

        if (cameron_busy == -1) {
            cameron_busy = i;
            schedule[sorted_activities[i].id] = 1;
        }
        else if (jamy_busy == -1) {
            jamy_busy = i;
            schedule[sorted_activities[i].id] = 0;
        }
        else {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for(int p: schedule) {
            if (p == 0) {
                cout << "J";
            }
            else if (p == 1) {
                cout << "C";
            }
            else {
                cout << "Error: activity not assigned" << endl;
                exit(1);
            }
        }
        cout << endl;
    }
  
    return solved;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for(int test_case=0; test_case<test_cases; ++test_case) {
        Problem problem;
        int nb_activities;
        cin >> nb_activities;

        for(int i=0; i<nb_activities; i++) {
            Activity activity;
            activity.id = i;
            cin >> activity.start_time >> activity.end_time;
            problem.activities.push_back(activity);
        }
        std::cout << "Case #" << test_case+1 << ": ";
        assert(problem.solve());
    }

    return 0;       
}