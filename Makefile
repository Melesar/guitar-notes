CC = gcc
CFLAGS = -Wall
TARGET = notesDictator
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
