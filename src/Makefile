CC = gcc
CFLAGS = -Wall
TARGET = guitar-notes
OBJS = main.o cheatsheet.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c -o$@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o

.PHONY: $(TARGET) clean
