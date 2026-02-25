#include "physics_engine.h"

void update_physics(Ball *ball, double dt, int screenWidth, int screenHeight) {
    /* 重力を加算 */
    ball->vy += GRAVITY * dt;

    /* 位置を更新 */
    ball->x += ball->vx * dt;
    ball->y += ball->vy * dt;

    /* --- 跳ね返り処理 --- */
    float radius = (float)BALL_RADIUS; /* ボールの半径 */

    /* 左右の壁 */
    /* 右端にいて、かつ右向き（正）に動いているなら反転 */
    if (ball->x + radius > screenWidth && ball->vx > 0) {
        ball->vx *= -1;
        ball->x = screenWidth - radius; /* 位置補正 */
    }
    /* 左端にいて、かつ左向き（負）に動いているなら反転 */
    else if (ball->x - radius < 0 && ball->vx < 0) {
        ball->vx *= -1;
        ball->x = radius; /* 位置補正 */
    }

    /* 天井に触れていて、かつ速度が上向き（負）なら反転 */
    if (ball->y - radius < 0 && ball->vy < 0) {
        ball->vy *= -ENERGY_LOSS;
        ball->y = radius;
    }
    /* 床に触れていて、かつ速度が下向き（正）なら反転 */
    if (ball->y + radius > screenHeight && ball->vy > 0) {
        ball->vy *= -ENERGY_LOSS;
        ball->y = screenHeight - radius;
    }
}