OBJ=LookNBA.o main.o Mishu.o
HEAD=LookNBA.h Mishu.h Observer.h Subject.h
EXE=exe

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)

