OBJECTS = 2323402.o exam_word.o 
CC = gcc
TARGET = 2323402.exe

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

2323402.o : 2323402.c
	gcc -c -o 2323402.o 2323402.c

exam_word.o : exam_word.c
	gcc -c -o exam_word.o exam_word.c


clean:
	rm *.o $(TARGET)
