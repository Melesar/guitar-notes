CC = gcc
CFLAGS = -Wall
TARGET = guitar-notes
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/cheatsheet.o
OBJ_DIR = bin

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(OBJ_DIR)/$@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $<

run: $(TARGET)
	$(OBJ_DIR)/$(TARGET)

ifeq ($(shell whoami),root)
install: $(TARGET)
	cp $(OBJ_DIR)/$(TARGET) /usr/bin/$(TARGET)
uninstall:
	rm /usr/bin/$(TARGET)
else
install:
	@echo "Use sudo make install"
uninstall:
	@echo "Use sudo make uninstall"
endif

clean:
	rm -rf $(OBJ_DIR)

.PHONY: $(TARGET) clean install uninstall
