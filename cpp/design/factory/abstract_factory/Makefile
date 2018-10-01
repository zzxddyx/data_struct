OBJ=main.o
HEAD=FactoryA.h  FactoryB.h  Factory.h Product1.h  Product2.h  ProductA1.h  ProductA2.h  ProductB1.h  ProductB2.h
BIN=exe

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)

