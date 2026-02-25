#include "physics_engine.h"

float update_velocity(float v, float g) {
    return v + g;
}

float update_position(float y, float v) {
    return y + v;
}