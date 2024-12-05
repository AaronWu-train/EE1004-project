# 編譯器與編譯選項
CC = g++
CFLAGS = -Wall -O2

# 資料夾
SRC_DIR = src
BIN_DIR = bin
DIST_DIR = dist

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

.PHONY: all archive prepare_dist clean
