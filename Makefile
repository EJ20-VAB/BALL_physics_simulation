# 実行環境
CC = gcc
CFLAGS = -I include -Wall
SRC_DIR = src
TARGET = physics.exe
TEST_TARGET = test_physics.exe

SRCS = $(SRC_DIR)/physics.c $(SRC_DIR)/physics_engine.c
TEST_SRCS = $(SRC_DIR)/test_physics.c $(SRC_DIR)/physics_engine.c

LDFLAGS = -lraylib -lgdi32 -lwinmm

# OSを判定して削除コマンドを切り替える(おまじない)
ifeq ($(OS),Windows_NT)
    RM = del /Q
    # Windowsのdelコマンドはファイルがないとエラーを吐くので、存在チェックを挟む工夫
    CLEAN_CMD = if exist $(TARGET) $(RM) $(TARGET) && if exist $(TEST_TARGET) $(RM) $(TEST_TARGET)
else
    RM = rm -f
    CLEAN_CMD = $(RM) $(TARGET) $(TEST_TARGET)
endif

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

test: $(TEST_SRCS)
	$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) $(LDFLAGS)
	./$(TEST_TARGET)

# 警告が出ないよう、cleanは1つだけに絞る
clean:
	$(CLEAN_CMD)