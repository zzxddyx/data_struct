OBJ=doubleList.o doubleListMain.o
HEAD=doubleList.h
BIN=bin

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11 -g
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)

