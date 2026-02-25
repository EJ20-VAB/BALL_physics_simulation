#include <stdio.h>
#include <assert.h>
#include "physics_engine.h"

int main() {
    printf("Running unit tests...\n");

    // 速度更新のテスト
    assert(update_velocity(1.0, 0.5) == 1.5);
    
    // 位置更新のテスト
    assert(update_position(10.0, 2.0) == 12.0);

    printf("All tests passed successfully!\n");
    return 0;
}