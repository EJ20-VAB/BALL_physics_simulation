#include <assert.h>
#include <stdio.h>
#include "physics_engine.h"

/* 重力によって速度が正しく加算されるかをテスト */
void test_gravity() {
    /* ボールを静止状態で初期化 */
    Ball ball = {0.0, 0.0, 0.0, 0.0};
    
    /* ヘッダーで定義された DT を使用して更新 */
    update_physics(&ball, DT, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    /* デバッグ用：計算後の速度を表示 */
    printf("Debug (Gravity): ball.vy = %f\n", ball.vy);
    
    /* 速度 vy が GRAVITY * DT 分だけ増えているかを確認 */
    /* 浮動小数点の誤差を考慮し、0より大きいことを検証 */
    assert(ball.vy > 0);
    printf("test_gravity passed!\n");
}

/* 画面端での跳ね返りロジックをテスト */
void test_bounce() {
    /* 右端ギリギリに配置し、右向きに速度を持たせる */
    /* BALL_RADIUS を考慮して計算 */
    Ball ball = {SCREEN_WIDTH - BALL_RADIUS - 1.0, 100.0, 100.0, 0.0};
    
    /* 更新を実行。次のステップで壁を越える */
    update_physics(&ball, DT, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    /* デバッグ用：跳ね返り後の速度を表示 */
    printf("Debug (Bounce): ball.vx = %f\n", ball.vx);
    
    /* 壁に当たって速度 vx が反転（負の値）しているかを確認 */
    assert(ball.vx < 0);
    printf("test_bounce passed!\n");
}

int main() {
    printf("Starting Physics Engine Tests...\n");
    printf("--------------------------------\n");

    test_gravity();
    test_bounce();

    printf("--------------------------------\n");
    printf("All tests passed successfully!\n");
    
    return 0;
}