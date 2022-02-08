#include <stdio.h>
#include "transytivien.h"

int main(const int argc, const char** argv)
{
    for (int i = 0; i <= 30; i++)
    {
        printf("Jahr %d - Knoblauchbaeuer_innen: %d Vampir_innen: %d Werwoelfe: %d\n", i, knoblauchbauern(i), vampire(i), werwoelfe(i));
    }
    return 0;
}
