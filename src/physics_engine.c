#include "physics_engine.h"

float update_velocity(float v, float g) {
    return v + g;
}

float update_position(float y, float v) {
    return y + v;
}

void update_physics(Ball *ball, double dt) {
    /* 1. 垂直方向の速度に重力加速度を加算 */
    ball->vy += GRAVITY * dt;

    /* 2. 位置を更新 (x = x + v*dt) */
    ball->x += ball->vx * dt;
    ball->y += ball->vy * dt;
}