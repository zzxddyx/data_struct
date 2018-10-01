#--------------1----------
#exe:main.o add.o sub.o div.o
#	gcc -o exe main.o add.o sub.o div.o 
#main.o:main.c head.h
#	gcc -c main.c
#add.o:add.c head.h
#	gcc -c add.c
#sub.o:sub.c head.h
#	gcc -c sub.c
#div.o:div.c head.h
#	gcc -c div.c
#
#clean:
#	rm main.o add.o sub.o div.o

#-----------2----------
#objects = main.o add.o \
		  sub.o div.o

#exe:$(objects)
#	cc -o exe $(objects)
#main.o:main.c head.h
#	gcc -c main.c
#add.o:add.c head.h
#	gcc -c add.c
#sub.o:sub.c head.h
#	gcc -c sub.c
#div.o:div.c head.h
#	gcc -c div.c

#clean:
#	rm $(objects)

#---------3-----------
#objects = main.o add.o \
#		  sub.o div.o
#exe:$(objects)
#	cc -o exe $(objects)

#main.o:head.h
#add.o:head.h
#sub.o:head.h
#div.o:head.h

#clean:
#	rm $(objects)
	
#objects = main.o add.o \
		  sub.o div.o
#exe:$(objects)
#	cc -o exe $(objects)

#main.o add.o sub.o div.o:head.h

#.PHONY:clean
#clean:
#	rm $(objects) 
#

#OBJ = main.o add.o sub.o div.o
#HEAD = head.h
#CALC = exe

#$(CALC):$(OBJ)
#	$(CC) -o $(CALC) $(OBJ)

#$(OBJ):$(HEAD)

#clean:
#	-$(RM) $(OBJ)

OBJ = main.o add.o sub.o div.o
HEAD = head.h
CALC = exe

$(CALC):$(OBJ)
	$(CC) -o $@ $^
$(OBJ):$(HEAD)

clean:
	-$(RM) $(OBJ)


