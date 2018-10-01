# 方式一
#bin:main.o class.o
#	g++ -o bin main.o class.o -std=c++11
#main.o:main.cpp class.h
#	g++ -o main.o -c main.cpp
#class.o:class.cpp class.h
#	g++ -o class.o -c class.cpp
#
#clean:
#	rm class.o main.o

#方式二
#objects=main.o class.o
#bin:$(objects)
#	g++ -o bin $(objects) -std=c++11
#main.o:main.cpp class.h
#	g++ -o main.o -c main.cpp -std=c++11
#class.o:class.cpp class.h
#	g++ -o class.o -c class.cpp -std=c++11
#
#clean:
#	rm $(objects)

#方式三
#objects = main.o class.o
#bin:$(objects)
#	$(CXX) -o bin $(objects) -std=c++11
#main.o:class.h
#class.o:class.h
#
#clean:
#	rm $(objects)

#方式四
#objects=main.o class.o
#bin:$(objects)
#	$(CXX) -o bin $(objects) -std=c++11
#
#main.o class.o:class.h 
#
#.PHONY:clean
#clean:
#	rm -rf $(objects)

#方式五
#OBJ=main.o class.o
#HEAD=class.h
#CLASS=bin
#
#$(CLASS):$(OBJ)
#	$(CXX) -o $(CLASS) $(OBJ) -std=c++11
#
#$(OBJ):$(HEAD)
#
#clean:
#	-$(RM) $(OBJ)

#方式六 
OBJ=main.o class.o
HEAD=class.h
CLASS=bin

$(CLASS):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)
clean:
	$(RM) $(OBJ)
