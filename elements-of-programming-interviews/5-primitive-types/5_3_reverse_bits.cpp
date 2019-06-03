unsigned long long ReverseBits(unsigned long long x) {
    unsigned long long ret = 0;
        
    for (int i = 0; i < 64; ++i) {
        int curr = x & 1;
        x >>= 1;
        ret <<= 1;
        ret |= curr;
    }   

    return ret;
}