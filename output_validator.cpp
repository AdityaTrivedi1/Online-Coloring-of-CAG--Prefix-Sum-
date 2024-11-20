#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int> > arcs;
    for (int z = 0; z < n; z++) {
        vector<int> arc;
        int ep = -1;
        cin >> ep;
        arc.push_back(ep);
        cin >> ep;
        arc.push_back(ep);
        arcs.push_back(arc);
    }
    vector<vector<int> > colors;
    for (int z = 0; z < n; z++) {
        vector<int> color;
        int num = -1;
        cin >> num;
        color.push_back(num);
        cin >> num;
        color.push_back(num);
        colors.push_back(color);
    }
    for (int z = 0; z < n-1; z++) {
        bool is_left_reverse = (arcs[z][0] > arcs[z][1]) ? true : false;
        for (int y = z + 1; y < n; y++) {
            bool is_right_reverse = (arcs[y][0] > arcs[y][1]) ? true : false;
            bool is_intersecting = false;
            
            if (!is_left_reverse && !is_right_reverse && arcs[z][0] <= arcs[y][1] && arcs[z][1] >= arcs[y][0]) is_intersecting = true;
            if (is_left_reverse && !is_right_reverse && !(arcs[z][1] < arcs[y][0] && arcs[y][1] < arcs[z][0])) is_intersecting = true;
            if (!is_left_reverse && is_right_reverse && !(arcs[y][1] < arcs[z][0] && arcs[z][1] < arcs[y][0])) is_intersecting = true;
            if (is_left_reverse && is_right_reverse) is_intersecting = true;

            if (is_intersecting && colors[z][0] == colors[y][0] && colors[z][1] == colors[y][1]) {
                cout << "Infeasible color (" << colors[z][0] << ", " << colors[z][1] << ") for arcs " 
                     << "(" << (z + 1) << ") - ("
                     << arcs[z][0] << ", " << arcs[z][1] << ") and "
                     << "(" << (y + 1) << ") - ("
                     << arcs[y][0] << ", " << arcs[y][1] << ")\n";
                return 0;
            }
        }
    }
    cout << "All colors are feasible\n";
    return 0;
}

