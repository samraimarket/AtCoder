#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
template <typename T = int>
T in() {
    T temp;
    cin >> temp;
    return temp;
}

list<size_t> const LR(size_t start, size_t end) {
    list<size_t> ret;
    for (size_t i = start; i < end; i++) ret.push_back(i);
    return move(ret);
}

int main() {
  
    return 0;
}


