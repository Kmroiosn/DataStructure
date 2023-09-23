#include <string.h>
#include "../stringMain.hpp"

int Index_BF(sString S, sString T, int pos)
{
    #if 1
    int i = pos;
    int j = 1;
    #endif
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}
