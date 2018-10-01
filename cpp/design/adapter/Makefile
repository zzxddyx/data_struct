OBJ=main.o SocketAdapter.o
HEAD=SocketAdapter.h Socket.h SocketPackage.h
BIN=exe

$(BIN):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)
