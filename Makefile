CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lncurses -lm
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SRCS = $(addprefix $(SRCDIR)/,main.c tree.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY: all
all: $(BINDIR)/prog

$(BINDIR)/prog: $(OBJS) | $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	[ -d $(OBJDIR) ] || mkdir $(OBJDIR)

$(BINDIR):
	[ -d $(BINDIR) ] || mkdir $(BINDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
