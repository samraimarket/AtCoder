#include <iostream>

using namespace std;
template <typename T = int>
T in() {
    T temp;
    cin >> temp;
    return temp;
}

class XorWorld {
    uint64_t const A;
    uint64_t const B;
    uint64_t const diff;

    static uint64_t constexpr period = 4; // = 100b
    static uint64_t constexpr periodicMask = period - 1; // = 011b

    uint64_t GetXor () const {
        uint64_t ret;
        for (uint64_t i = A; i <=B; i++) {
            if (i == A) ret = i;
            else ret ^= i;
        }
        return ret;
    }

    uint64_t GetShortenA() const {
        uint64_t newDiff = (diff & periodicMask);
        if (newDiff == 0) newDiff = 4;
        return B - newDiff + 1;
    }

public : 
    XorWorld(uint64_t A_p, uint64_t B_p) : A(min(A_p, B_p)), B(max(A_p,B_p)), diff(B - A + 1) {}

    uint64_t Calculate() const {

        // When the size is too small, no problem even calculate greedly
        if (diff < (period + 1)) return GetXor();
       
        // Otherwise retry calculating after getting new A
        // If the A is even number.
        // Shorten A to (B - 1), (B - 2), (B - 3).            
        //return subWorld.Calculate();
        if ((A & 1) == 0) return XorWorld(GetShortenA(), B).GetXor();

        // Otherwise A is odd number and size is very large.
        // Separate numbers to A and then after((A + 1)(must be even number) to B)
        // Then calculate recursively.
        return A ^ XorWorld(A + 1, B).Calculate();
    }
};
int main() {
    uint64_t A(in<uint64_t>()), B(in<uint64_t>());
    XorWorld const world(A, B);
    cout << world.Calculate() << endl;
    return 0;
}


