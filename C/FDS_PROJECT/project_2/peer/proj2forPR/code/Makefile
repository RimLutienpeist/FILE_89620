CC = g++
CFLAGS = -Wall -pedantic -std=c++11

SRCS = main.cpp autograd.cpp check.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = autograd

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
