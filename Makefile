CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRC = Graph.cpp Algorithms.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = Main
TEST_EXEC = test
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: test.cpp Graph.cpp Algorithms.cpp
	$(CC) $(CFLAGS) test.cpp Graph.cpp Algorithms.cpp -o $(TEST_EXEC)

valgrind: $(EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC) $(TEST_EXEC)
