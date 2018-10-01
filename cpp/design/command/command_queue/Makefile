OBJ=Invoker.o main.o Reveiver.o 
HEAD=Command.h Invoker.h PayCommand.h Reveiver.h TakeCommand.h
BIN=exe

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
