


TARGET = server

OBJS=Server.o Infos.o InfosI.o



LIBS = -L$(ACE_ROOT)/lib -lACE  -lIceUtil\
-L$(ICE_HOME)/lib -lIce -lIceUtil -lIceStorm



#使用ICE必须添加-I.，否则会出现无法找到ice生成的。h文件的问题
INCLUDES = -I$(ACE_ROOT) \
            -I. -I$(ICE_HOME)/include


CFLAGS = -g

LFLAGS=

$(TARGET):$(OBJS)
	$(CC) $(LFLAGS) -o $(TARGET) $(OBJS) $(LIBS)


$(OBJS):%.o:%.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@


.PHONY : clean
clean:
	rm $(TARGET) $(OBJS)











