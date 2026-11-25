#include "../include/spruce.h"

#include <stdio.h>

int main(void) { 
    spruce_pool p;
    if (!spruce_init(&p, 32, sizeof(unsigned long)))
        return 1;

    printf("%d\n", spruce_acquire(&p, 0));
    return 0;
}
