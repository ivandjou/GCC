#include <stdio.h>

void f1(int var)
{
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var)
{
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var)
{
    printf("this is f3 and var is: %d\n", var);
}

int main()
{
    // Déclaration du tableau de pointeurs vers fonctions
    void (*functions[3])(int) = {f1, f2, f3};

    int c = 0;
    while (c < 3)
    {
        // Appel des fonctions via le tableau de pointeurs
        functions[c](c);
        ++c;
    }

    return 0;
}

