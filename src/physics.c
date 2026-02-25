#include <stdio.h>
#include <unistd.h>
#include "physics_engine.h"

int main() {
    float y = 0, v = 0, g = 0.1;
    while (1) {
        v = update_velocity(v, g);
        y = update_position(y, v);
        
        if (y >= 20) { y = 20; v *= -0.8; }
        
        printf("\033[H\033[J");
        for (int i = 0; i < (int)y; i++) printf("\n");
        printf("  [O]  \n");
        usleep(50000);
    }
    return 0;
}