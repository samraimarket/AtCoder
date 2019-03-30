#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
template <typename T = int>
T in() {
    T temp; cin >> temp; return temp;
}

template <typename VType = int>
list<VType> const LR(VType start, VType end) {
    list<VType> ret; for (VType i = start; i < end; i++) ret.push_back(i); return move(ret);
}

int main() {
    return 0;
}


