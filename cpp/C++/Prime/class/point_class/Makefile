OBJ=main.o point_class.o
HEAD=point_class.h
EXE=bin

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11

$(OBJ):$(HEAD)
clean:
	$(RM) $(OBJ)

