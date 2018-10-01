OBJ:main.o union.o
HEAD:union.h
EXE:bin

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11

$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
