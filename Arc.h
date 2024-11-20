#include <vector>
using namespace std;

class Arc {
    public:
        int l;
        int r;
        int shelf;
        int level;
        Arc(int l, int r, int shelf, int level) {
            this -> l = l;
            this -> r = r;
            this -> shelf = shelf;
            this -> level = level;
        }
};