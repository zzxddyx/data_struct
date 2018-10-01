OBJ=main.o Value_class.o
HEAD=Value_class.h
EXE=bin

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11

$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
