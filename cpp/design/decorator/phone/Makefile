OBJ=main.o
HEAD=DecoratoriPhone.h DecoratorNokiaPhone.h DecoratorPhone.h iPhone.h NokiaPhone.h Phone.h
EXE=exe

$(EXE):$(OBJ)
	$(CXX) -o $@ $^ -g -std=c++11
$(OBJ):$(HEAD)
	
clean:
	$(RM) $(OBJ)


