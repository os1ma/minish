CC = gcc

CFLAGS = -Wall -W -O2

TARGET = minish

SRCS = minish.c $(YYC)
OBJS = $(SRCS:.c=.o)

LEX  = lex.l
YYC  = $(LEX:.l=.yy.c)

$(TARGET): $(OBJS)
	$(CC) -lfl -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(YYC): $(LEX)
	flex -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS) $(YYC)
