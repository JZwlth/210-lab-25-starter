#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;



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
