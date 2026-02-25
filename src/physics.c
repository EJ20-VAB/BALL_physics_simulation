#include <stdio.h>
#include <unistd.h>
#include "physics_engine.h"
#include "raylib.h"

int main(void) {
    /* 画面のサイズ設定 */
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    /* ウィンドウの初期化 */
    InitWindow(screenWidth, screenHeight, "Physics Simulation - Ball Falling");

    /* ボールの初期状態 */
    Ball myBall = { BALL_INIT_POS_X, BALL_INIT_POS_Y, BALL_INIT_VX, BALL_INIT_VY }; // x, y, vx(初速), vy

    SetTargetFPS((int)FPS); /* FPS:60の設定 */

    /* --- メイン描画ループ --- */
    while (!WindowShouldClose()) {
        /*  Update: 物理演算 */
        update_physics(&myBall, DT, screenWidth, screenHeight);

        /* Draw: 描画 */
        BeginDrawing();
            ClearBackground(RAYWHITE); // 画面を白でリセット

            /* ボールを描画 (座標x, y, 半径, 色) */
            DrawCircle((int)myBall.x, (int)myBall.y, (int)BALL_RADIUS, MAROON);

            DrawText("Press ESC to exit", UI_MARGIN, UI_LINE_HEIGHT, UI_TEXT_SIZE, GRAY);
        EndDrawing();
    }

    CloseWindow(); /* ウィンドウを閉じる */
    return 0;
}