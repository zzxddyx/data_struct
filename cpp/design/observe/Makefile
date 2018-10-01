OBJ=main.o QQGroup.o RoomMate.o 
HEAD=Observer.h QQGroup.h RoomMate.h Subject.h
EXE=exe

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	$(RM) $(OBJ)



