CC = gcc
CFLAGS = -W -Wall
TARGET = diary_exe
SOURCES = memo.c main.c calender.c
OBJECTS = $(SOURCES: .c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o diary_exe
