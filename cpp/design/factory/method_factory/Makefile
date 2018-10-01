OBJ=main.o
HEAD=Factory_A.h Factory_B.h Factory.h Product_A.h Product_B.h Product.h
EXE=exe

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
