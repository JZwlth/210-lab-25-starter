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

// Function templates for inserting elements
template <typename Container>
void inserter(Container& container, const string& value) {
    container.push_back(value);  // For vector and list
}

template <>
void inserter(set<string>& container, const string& value) {
    container.insert(value);  // For set
}

// Function to read data into a container
template <typename Container>
int read_data(Container& container, const string& filename) {
    auto start = high_resolution_clock::now();
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        inserter(container, line);
    }
    file.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count();
}

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

// Functions to delete the middle-ish element
int delete_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
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

    // READING race
    times["Vector"]["Read"] = read_data(vec, "codes.txt");  // Updated filename
    times["List"]["Read"] = read_data(lst, "codes.txt");    
    times["Set"]["Read"] = read_data(st, "codes.txt");      

    // SORTING race
    times["Vector"]["Sort"] = sort_vector(vec);
    times["List"]["Sort"] = sort_list(lst);
    times["Set"]["Sort"] = -1;  // Set is already sorted

    // INSERTING race
    times["Vector"]["Insert"] = insert_vector(vec, "TESTCODE");
    times["List"]["Insert"] = insert_list(lst, "TESTCODE");
    times["Set"]["Insert"] = insert_set(st, "TESTCODE");

    // DELETING race
    times["Vector"]["Delete"] = delete_vector(vec);
    times["List"]["Delete"] = delete_list(lst);
    times["Set"]["Delete"] = delete_set(st);

    // Output the results
    cout << setw(12) << "Operation";
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
