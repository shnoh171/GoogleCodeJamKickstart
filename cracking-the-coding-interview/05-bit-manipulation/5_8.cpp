#include <vector>
using namespace std;

void DrawLine(vector<char> &screen, int width, int y, int x1, int x2) {
    int start_index = y * (width/8) + x1/8;
    int end_index = y * (width/8) + x2/8;
    int start_bit = x1 % 8;
    int end_bit = x2 % 8;

    for (int i = start_bit + 1; i < end_bit; ++i)
        screen[i] = 0x7;
    
    if (start_bit == 0)
        screen[start_index] = 0x7;
    else
        screen[start_index] = (1 << (8 - start_bit)) - 1;

    if (start_index != end_index) {
        screen[end_index] = ~(char)((1 << (7 - end_bit)) - 1);
    } else {
        screen[end_index] &= ~(char)((1 << (7 - end_bit)) - 1);
    }
}