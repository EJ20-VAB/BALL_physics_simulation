#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

/* 重力加速度 (ピクセル/秒^2) */
#define GRAVITY 9.81

/* ボールの状態 */
typedef struct {
    double x, y;   // 位置
    double vx, vy; // 速度
} Ball;

// 物理計算ロジックの宣言
float update_velocity(float v, float g);
float update_position(float y, float v);
/* 経過時間 dt を受け取るように変更）*/
void update_physics(Ball *ball, double dt, int screenWidth, int screenHeight);

#endif