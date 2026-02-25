#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

/* 画面設定 */
/* 画面サイズ */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
/* UI上の文字描画設定 */
#define UI_MARGIN 10
#define UI_LINE_HEIGHT 10
#define UI_TEXT_SIZE 20

/* 重力加速度 (ピクセル/秒^2) */
#define GRAVITY 9.81
/* エネルギーロス */
#define ENERGY_LOSS 0.8

/* フレームレート設定 */
#define FPS 60.0
/* 経過時間 */
#define DT 1.0/FPS

/* ボールの状態 */
/* ボールの初期状態 */
#define BALL_INIT_POS_X 100.0   /* 初期位置X */
#define BALL_INIT_POS_Y 50.0    /* 初期位置Y */
#define BALL_INIT_VX 200.0      /* 初速X */
#define BALL_INIT_VY 0.0        /* 初速Y */
/* ボールの半径 */
#define BALL_RADIUS 20.0
/* ボール構造体*/
typedef struct {
    double x, y;   /* 位置 */
    double vx, vy; /* 速度 */
} Ball;

/* 物理計算ロジックの宣言 */
float update_velocity(float v, float g);
float update_position(float y, float v);
/* 物理演算の宣言 */
void update_physics(Ball *ball, double dt, int screenWidth, int screenHeight);

#endif