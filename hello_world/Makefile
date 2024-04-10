# Setup directories
SRCDIR		:= src
BINDIR		:= bin
BUILDDIR	:= build

# Setup sources
SRCS 	+= $(wildcard $(SRCDIR)/*.c)

# Output files
NAME	:= hello_world
BIN		:= $(BINDIR)/$(NAME)

# Compiler settings and flags
CC		:= gcc
CFLAGS	:= -g -Wall -O2

# Libraries to link against
LIB		:=

# Object files
OBS		:= $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCS))

# Generate header dependencies so we can include them in subsequent builds.
DEPDIR := $(BUILDDIR)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Handle automatic rebuild of c files when headers change (generated in c rules below).
-include $(OBJS:.o=.d)

all: $(BIN)
	@echo
	@echo Built $(BIN)
	@echo

run: $(BIN)
	$(BIN)

# Link objects into BIN
$(BIN): $(OBJS) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

# Build object files
$(BUILDDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
	rm -rf $(BINDIR)