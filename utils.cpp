typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

inline int
clamp(int min, int val, int max)
{
    if (val < min)
        return min;
    if (val > max)
        return max;

    return val;
}