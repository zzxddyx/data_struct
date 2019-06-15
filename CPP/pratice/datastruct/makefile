OBJ=list.o listMain.o
HEAD=list.h
BIN=bin

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11 -g
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)

