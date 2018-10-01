OBJ=main.o Singleton.o
HEAD=Singleton.h
BIN=exe

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)

