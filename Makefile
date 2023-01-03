CC = gcc
CFLAGS = -Wall -O2

TARGET = minish

SRCS = minish.c
OBJS = $(SRCS:.c=.o)


$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(TARGET) $(OBJS)
