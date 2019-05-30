OBJ=main.o MyString.o
HEAD=MyString.h
BIN=bin

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11 -g
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
