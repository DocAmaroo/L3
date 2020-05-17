CC = g++
CFLAGS = -Wall
SOURCE = $(wildcard *.cc)
PROGNAME = run

MSQ = @
RM = $(MSQ)rm -f
CLEAR = $(MSQ)clear

MSG = $(MSQ)echo 
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG_OK = $(MSG) ".......OK"

all : $(PROGNAME)

#clean
cls :
	$(RM) *.o
	$(RM) $(SOURCE:.cc=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

#Compilation
$(PROGNAME) : $(SOURCE:.cc=.o)
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(CLEAR)
	$(MSG_OK)
