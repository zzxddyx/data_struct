OBJ=FlyNoWay.o FlyWithWings.o main.o MallardDuck.o MuteQuack.o Quack.o Squeak.o FlyWithWings.o Duck.o
HEAD=Duck.h FlyBehavior.h QuackBehavior.h FlyWithWings.h FlyNoWay.h QuackBehavior.h Quack.h
CLASS=bin

$(CLASS):$(OBJ)
	$(CXX) -o $@ $^ -std=c++11
$(OBJ):$(HEAD)

clean:
	-$(RM) $(OBJ)
