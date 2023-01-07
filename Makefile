CC = gcc

CFLAGS = -Wall -O2

TARGET = minish

SRCS = minish.c
OBJS = $(SRCS:.c=.o)
LEX  = lex.l
YYC  = $(LEX:.l=.yy.c)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(YYC): $(LEX)
	flex -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS) $(YYC)
