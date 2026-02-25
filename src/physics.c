#include <stdio.h>
#include <unistd.h>
#include "physics_engine.h"
#include "raylib.h"

int main(void) {
    /* 画面のサイズ設定 */
    const int screenWidth = 800;
    const int screenHeight = 450;

    /* ウィンドウの初期化 */
    InitWindow(screenWidth, screenHeight, "Physics Simulation - Ball Falling");

    /* ボールの初期状態 */
    Ball myBall = { 100.0, 50.0, 200.0, 0.0 }; // x, y, vx, vy

    SetTargetFPS(60); /* 1秒間に60回ループさせる設定 */

    /* --- メイン描画ループ --- */
    while (!WindowShouldClose()) {
        /*  Update: 物理演算 */
        update_physics(&myBall, 1.0/60.0);

        /* Draw: 描画 */
        BeginDrawing();
            ClearBackground(RAYWHITE); // 画面を白でリセット

            /* ボールを描画 (座標x, y, 半径, 色) */
            DrawCircle((int)myBall.x, (int)myBall.y, 20, MAROON);

            DrawText("Press ESC to exit", 10, 10, 20, GRAY);
        EndDrawing();
    }

    CloseWindow(); /* ウィンドウを閉じる */
    return 0;
}