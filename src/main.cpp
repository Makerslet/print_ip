#include "to_string.h"

int main (int, char **)
{
    char ch = -1;
    to_string(ch);

    short sh = 0;
    to_string(sh);

    int i = 2130706433;
    to_string(i);

    long l = 8875824491850138409;
    to_string(l);

    return 0;
}


