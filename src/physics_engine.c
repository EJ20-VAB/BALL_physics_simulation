#include "physics_engine.h"

float update_velocity(float v, float g) {
    return v + g;
}

float update_position(float y, float v) {
    return y + v;
}

void update_physics(Ball *ball, double dt, int screenWidth, int screenHeight) {
    /* 重力を加算 */
    ball->vy += GRAVITY * dt;

    /* 位置を更新 */
    ball->x += ball->vx * dt;
    ball->y += ball->vy * dt;

    /* --- 跳ね返り処理 --- */
    float radius = 20.0f; /* ボールの半径 */

    /* 左右の壁 */
    if (ball->x + radius > screenWidth || ball->x - radius < 0) {
        ball->vx *= -1; // 向きを反転
    }

    /* 床と天井 */
    if (ball->y + radius > screenHeight || ball->y - radius < 0) {
        ball->vy *= -0.8; /* 少し威力を弱めて跳ね返す（エネルギーロス）*/
        
        /* めり込み防止（床に埋まらないように位置を補正） */
        if (ball->y + radius > screenHeight) ball->y = screenHeight - radius;
        if (ball->y - radius < 0) ball->y = radius;
    }
}