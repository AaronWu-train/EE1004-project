# 編譯器與編譯選項
CC = g++
CFLAGS = -Wall -O2

# 資料夾
SRC_DIR = src
BIN_DIR = bin
DIST_DIR = dist
TEST_DIR = tests
INCLUDE_DIR = include

# 從 .env 檔案讀取學號
-include .env
STUDENT_ID ?= unknown
ARCHIVE_DIR = $(DIST_DIR)/$(STUDENT_ID)
ARCHIVE = $(DIST_DIR)/$(STUDENT_ID).zip

# 檔案
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES := $(wildcard $(SRC_DIR)/*.h)  # 找到所有的 .h 檔案
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))
EXECUTABLE = $(BIN_DIR)/main

# Test 檔案
TEST_SRC := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.cpp, $(BIN_DIR)/%.o, $(TEST_SRC))
TEST_EXECUTABLE = $(BIN_DIR)/test

# 指定要打包的檔案
FILES_TO_ARCHIVE = $(wildcard $(SRC_DIR)/*.h)

# 預設目標
all: $(EXECUTABLE)

# 編譯規則
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(SRC_DIR) -c $< -o $@

$(TEST_EXECUTABLE): $(TEST_OBJ) 
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCLUDE_DIR) -I$(SRC_DIR)

# 執行測試目標
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# 打包目標
archive: prepare_dist
	zip -r $(ARCHIVE) $(ARCHIVE_DIR)

prepare_dist:
	@mkdir -p $(ARCHIVE_DIR)
	@for file in $(FILES_TO_ARCHIVE); do \
	    cp $$file $(ARCHIVE_DIR); \
	done

# 清理目標
clean:
	rm -rf $(BIN_DIR) $(DIST_DIR) $(ARCHIVE)

.PHONY: all archive prepare_dist clean test
