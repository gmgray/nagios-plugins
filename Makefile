# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
# 
BUILD = build

# the build target executable:
TARGET = $(BUILD)/oraQuery

# sources
SOURCES = src/oracle-query/oracle-query.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	$(RM) $(TARGET)