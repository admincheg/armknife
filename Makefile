MYSQL_CFLAGS := `mysql_config --cflags`
MYSQL_LIBS := `mysql_config --libs`
LIBS += ${MYSQL_LIBS}
CC = gcc
CFLAGS += -Wall -std=c99 ${MYSQL_CFLAGS}
LDFLAGS =

SOURCE_DIR = src
BIN_DIR = bin
SRC = $(SOURCE_DIR)/main.c \
      $(SOURCE_DIR)/menu.c \
      $(SOURCE_DIR)/mysql/mysql.c \
      $(SOURCE_DIR)/http/http.c
OBJ = $(SRC:%.c=%.o)
EXEC = $(BIN_DIR)/armyknife


all: header preexec $(EXEC)
	@echo
	@echo "================== All targets compiled ==================="
	@echo

.SUFFIXES: .c
header:
	@echo "              _____"
	@echo "            /      |"
	@echo "           /   _   |  _______ ___     ___ __   __"
	@echo "          /  /  |  | |   __  \   \   /   |  | |  |"
	@echo "         /  /   |  | |  |  \  |   \_/    |  |_|  |"
	@echo "        /  /____|  | |  |__/  | |\   /|  |____   |"
	@echo "       /   _____   | |   __  /  | \_/ |  |    |  |"
	@echo "      /  /      |  | |  |  \ \  |     |  | ___|  |"
	@echo "     /__/       |__| |__|   \_|_|     |__||______|"
	@echo "          ___     ___               __     _____"
	@echo "         |   |  /    /             |__|  /   _  \\"
	@echo "         |   | /    /                   /  /   \_|"
	@echo "         |   |/    / __   ____      __  |  |       ______"
	@echo "         |        / |  |/      \   |  |_|  |__   /  ___   \\"
	@echo "         |       /  |     __    \  |  |_    __| |  |    \  |"
	@echo "         |       \  |   /    \   | |  | |  |    |  |____/  |"
	@echo "         |        \ |  |      |  | |  | |  |    |   ______/ "
	@echo "         |   |\    \|  |      |  | |  | |  |    |  |      "
	@echo "         |   | \    \  |      |  | |  | |  |     \  \____"
	@echo "         |___|  \ ___\_|      |__| |__| |__|      \______|"
	@echo
	@echo
	@echo

header_objects:
	@echo
	@echo "=================== Compile object files =================="
	@echo

header_binaries:
	@echo
	@echo "===================== Compile binaries ===================="
	@echo

preexec:
	@mkdir -p $(BIN_DIR)

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	@echo 'Compile' $@
	@$(CC) -c $< -o $@ $(CFLAGS) $(LIBS)

$(EXEC): header_objects $(OBJ) header_binaries
	@echo 'Compile binary file' $(EXEC)
	@$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS) $(LIBS)

clean: header
	@echo
	@echo "=============== Clean compiled object files ==============="
	@echo
	@find . -name '*.o' -exec rm -vf '{}' \;
	@echo
	@echo "==================== Remove binaries ======================"
	@echo
	@rm -rvf bin/
	@echo
	@echo "================== All objects removed ===================="
	@echo
