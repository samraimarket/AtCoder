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
/*
uint64_t GetXor (uint64_t A, uint64_t B) {
    uint64_t ret;
    for (uint64_t i = A; i <=B; i++) {
        if (i == A) ret = i;
        else ret ^= i;
    }
    return ret;
}
*/
class XorWorld {
    uint64_t A;
    uint64_t B;
    uint64_t diff;

    static uint64_t constexpr period = 4;
    static uint64_t constexpr periodicMask = period - 1;
public : 
    XorWorld(uint64_t A_p, uint64_t B_p) : A(min(A_p, B_p)), B(max(A_p,B_p)), diff(B - A + 1) {}

    uint64_t GetXor (uint64_t A, uint64_t B) {
        uint64_t ret;
        for (uint64_t i = A; i <=B; i++) {
            if (i == A) ret = i;
            else ret ^= i;
        }
        return ret;
    }

    uint64_t Calculate() {
        uint64_t ret;
     if (diff < (period + 1)) {
            ret = GetXor(A, B);
        } else {
                    
            if ((A & 1) == 0) {
                
                diff = (diff & periodicMask);
                A = B - diff + 1;
                ret = GetXor(A, B);
               
            } else if ((B & 1) == 1) {
                diff = (diff & periodicMask);
                B = A + diff - 1;
                ret = GetXor(A, B);

            // Both are odd numbers
            } else {
                uint64_t A1 = A + 1;
                diff--;
                diff = (diff & periodicMask);
                A1 = B - diff + 1;
                ret = A ^ GetXor(A1, B);
            }
        }
        return ret;   
    }

};
int main() {
    uint64_t A(in<uint64_t>()), B(in<uint64_t>());
//    uint64_t diff = B - A + 1;
    XorWorld world(A, B);
   
//     cout << exa << endl; 
    cout << world.Calculate() << endl;
    return 0;
}


