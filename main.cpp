#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include "Arc.h"
#pragma clang diagnostic ignored "-Wc++11-extensions"
#define NUM_POINTS 360
using namespace std;
using namespace std::chrono;

int find_shelf(vector<int>&, int);
void print_colors(vector<int>, vector<int>, int);
int main() {
    int num_arcs = 0;
    cin >> num_arcs;
    vector<Arc*> arcs(num_arcs, NULL);
    vector<int> num_arcs_in_shelf(num_arcs, 0);
    vector<int> arc_shelf(num_arcs, -1);
    vector<int> arc_level(num_arcs, -1);
    for (int z = 0; z < num_arcs; z++) {
        int l, r;
        cin >> l >> r;
        arcs[z] = new Arc(l, r, -1, -1);
    }
    auto start = high_resolution_clock::now();
    for (int z = 0; z < num_arcs; z++) {
        int l = arcs[z] -> l;
        int r = arcs[z] -> r;
        bool is_right_arc_reverse = (l > r) ? true : false;
        for (int y = 0; y < z; y++) {
            Arc* left_arc = arcs[y];
            bool is_left_curr_reverse = (left_arc -> l > left_arc -> r) ? true : false;
            bool is_intersecting = false;

            if (!is_left_curr_reverse && !is_right_arc_reverse && l <= left_arc -> r && r >= left_arc -> l) is_intersecting = true;
            if (is_left_curr_reverse && !is_right_arc_reverse && !(r < left_arc -> l && left_arc -> r < l)) is_intersecting = true;
            if (!is_left_curr_reverse && is_right_arc_reverse && !(left_arc -> r < l && r < left_arc -> l)) is_intersecting = true;
            if (is_left_curr_reverse && is_right_arc_reverse) is_intersecting = true;

            if (is_intersecting) num_arcs_in_shelf[left_arc -> shelf]++;
        }
        int i = find_shelf(num_arcs_in_shelf, z + 1);
        // vector<int> levels(3, 0);
        // for (int y = 0; y < z; y++) {
        //     Arc* left_arc = arcs[y];
        //     bool is_left_curr_reverse = (left_arc -> l > left_arc -> r) ? true : false;
        //     bool is_intersecting = false;

        //     if (!is_left_curr_reverse && !is_right_arc_reverse && l <= left_arc -> r && r >= left_arc -> l) is_intersecting = true;
        //     if (is_left_curr_reverse && !is_right_arc_reverse && !(r < left_arc -> l && left_arc -> r < l)) is_intersecting = true;
        //     if (!is_left_curr_reverse && is_right_arc_reverse && !(left_arc -> r < l && r < left_arc -> l)) is_intersecting = true;
        //     if (is_left_curr_reverse && is_right_arc_reverse) is_intersecting = true;

        //     if (is_intersecting && i == left_arc -> shelf) levels[left_arc -> level]++;
        // }
        // int level = 0;
        // for (; levels[level] > 0; level++);
        arc_shelf[z] = i;
        arc_level[z] = 0; //level;
        arcs[z] = new Arc(l, r, i, 0/*level*/);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Output generated" << endl;
    cout << "Time taken : "
         << duration.count() / 1000.0 << " s" << endl;
    print_colors(arc_shelf, arc_level, num_arcs);
    return 0;
}
int find_shelf(vector<int>& num_arcs_in_shelf, int num_arcs) {
    int shelf = 10000000;
    if (num_arcs_in_shelf[0] == 0) shelf = 0;
    for (int z = 1; z < num_arcs; z++) {
        num_arcs_in_shelf[z] += num_arcs_in_shelf[z - 1];
        if (z < shelf && num_arcs_in_shelf[z] <= z) shelf = z;
        num_arcs_in_shelf[z - 1] = 0;
    }
    // for (int z = 0; z < num_arcs; z++) {
    //     if (num_arcs_in_shelf[z] <= z) {
    //         shelf = z;
    //         break;
    //     }
    // }
    // for (int z = 0; z < num_arcs; z++) {
    //     num_arcs_in_shelf[z] = 0;
    // }
    num_arcs_in_shelf[num_arcs - 1] = 0;
    return shelf;
}
void print_colors(vector<int> arc_shelf, vector<int> arc_level, int num_arcs) {
    ofstream fout;
    fout.open("./test_cases/1_h.txt", ios::app);
    fout << endl;
    for (int z = 0; z < num_arcs; z++) {
        fout << arc_shelf[z] << " " << arc_level[z] << endl;
    }
    fout.close();
}
