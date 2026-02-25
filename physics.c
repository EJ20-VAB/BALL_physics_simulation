#include <stdio.h>
#include <unistd.h> // usleep用

int main() {
    float y = 0.0f;    // 初期位置
    float v = 0.0f;    // 初期速度
    float g = 0.1f;    // 重力加速度
    float bounce = -0.8f; // 跳ね返り係数（マイナスで逆方向に）
    int ground = 20;   // 地面の行数

    while (1) {
        // 1. 物理計算
        v += g;      // 速度に重力を加える
        y += v;      // 位置に速度を加える

        // 2. 地面との衝突判定
        if (y >= ground) {
            y = ground;
            v *= bounce; // 速度を反転して減衰させる
        }

        // 3. 描画（ターミナルをクリアして新しい位置に表示）
        printf("\033[H\033[J"); // ターミナルをリフレッシュするエスケープシーケンス
        for (int i = 0; i < (int)y; i++) printf("\n");
        printf("  [O]  \n");

        usleep(50000); // 0.05秒待機 (20fps)
    }
    return 0;
}