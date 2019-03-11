#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;
template <typename T = int>
T in() {
    T temp;
    cin >> temp;
    return temp;
}


int main() {
    uint64_t A(in<uint64_t>()), B(in<uint64_t>());
    uint64_t temp;
    for (uint64_t i = A; i <=B; i++) {
        if (i == A) temp = i;
        else temp ^= i;
        cout << std::bitset<4>(i) << ' ' << std::bitset<4>(temp) << endl;
    }
     
    return 0;
}


