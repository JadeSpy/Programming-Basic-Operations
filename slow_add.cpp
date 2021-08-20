#include <bitset>
using bsize = bitset<16>;

bsize add(bsize one, bsize two) {
    bsize total;
    bool carry_next = false;
    for (int i = 0;i < one.size();i++) {
        auto remain1 = one[i] ^ two[i];
        auto carry1 = one[i] & two[i];
        total[i] = remain1 ^ carry_next;
       // cout << (carry_next ^ carry_next);
        
        carry_next = (remain1 & carry_next) | carry1;
    }
    if (carry_next) {}//Overflow
    return std::move(total);
    /*
    Carry1 = &
    Remain1 = XOR 

    final_remain = XOR remain1, carry input
    final_carry = (AND remain1, carry input) OR Carry 1
    */
}
