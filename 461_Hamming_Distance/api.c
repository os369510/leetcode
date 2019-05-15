const uint32_t m1  = 0x55555555; //binary: 0101...
const uint32_t m2  = 0x33333333; //binary: 00110011..
const uint32_t m4  = 0x0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint32_t m8  = 0x00ff00ff; //binary:  8 zeros,  8 ones ...
const uint32_t m16 = 0x0000ffff; //binary: 16 zeros, 16 ones ...
int hammingDistance(int x, int y){
    int xor = x ^ y;
    xor = (xor & m1 ) + ((xor >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
    xor = (xor & m2 ) + ((xor >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
    xor = (xor & m4 ) + ((xor >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
    xor = (xor & m8 ) + ((xor >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
    xor = (xor & m16) + ((xor >> 16) & m16); //put count of each 32 bits into those 32 bits 
    return xor;
}
