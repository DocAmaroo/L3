CC = g++
CFLAGS = -Wall -pedantic -ansi
SOURCE = $(wildcard *.cpp) 
OBJ = $(SOURCE:%.cpp=%.o)
EXE = run

MSQ = @
RM = $(MSQ)rm -f *- *.o $(EXE)
CLEAR = $(MSQ)clear

MSG = $(MSQ)echo 
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG_OK = $(MSG) ".......OK"

all : $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

#clean
cls :
	$(RM) *.o
	$(RM) $(SOURCE:.cpp=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

.SUFFIXES: .cpp .o

#Compilation
%.o: %.cpp
	$(MSG1)
	$(CC) -c $<
	$(CLEAR)
	$(MSG_OK)