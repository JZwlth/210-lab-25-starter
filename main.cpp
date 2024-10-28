#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <iomanip>
#include <map>
#include <algorithm>  

using namespace std;
using namespace std::chrono;


// Functions to sort containers
int sort_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

int sort_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    lst.sort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

// Functions to insert "TESTCODE" into the middle
int insert_vector(vector<string>& vec, const string& value) {
    auto start = high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

int insert_list(list<string>& lst, const string& value) {
    auto start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.insert(it, value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

int insert_set(set<string>& st, const string& value) {
    auto start = high_resolution_clock::now();
    st.insert(value);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}


int delete_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.erase(it);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

int delete_set(set<string>& st) {
    auto start = high_resolution_clock::now();
    auto it = st.begin();
    advance(it, st.size() / 2);
    st.erase(it);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

int main() {
    // Initialize data structures
    vector<string> vec;
    list<string> lst;
    set<string> st;

    map<string, map<string, int>> times;

    // List of operations and data structures
    vector<string> operations = {"Read", "Sort", "Insert", "Delete"};
    vector<string> data_structures = {"Vector", "List", "Set"};


    for (const auto& ds : data_structures) {
        cout << setw(12) << ds;
    }
    cout << endl;

    for (const auto& op : operations) {
        cout << setw(12) << op;
        for (const auto& ds : data_structures) {
            int time = times[ds][op];
            if (time == -1) {
                cout << setw(12) << "-1";
            } else {
                cout << setw(12) << time;
            }
        }
        cout << endl;
    }

    return 0;
}
