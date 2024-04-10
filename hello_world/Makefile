# Setup directories
SRCDIR		:= src
BINDIR		:= bin
BUILDDIR	:= build

# Setup sources
SRCS 	:= $(wildcard $(SRCDIR)/*.c)

# Output files
NAME	:= hello_world
BIN		:= $(BINDIR)/$(NAME)

# Compiler settings and flags
CC		:= gcc
CFLAGS	:= -g -Wall -O2

# Libraries to link against
LIB		:=

# Object files
OBJS		:= $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCS))

# Generate header dependencies so we can include them in subsequent builds.
DEPDIR := $(BUILDDIR)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Handle automatic rebuild of c files when headers change (generated in c rules below).
-include $(OBJS:.o=.d)

# Print each entry on a new line
# These defines are important for proper functioning of newlineprint
NULL	:=
SPACE	:= $(NULL) $(NULL)
define NEWLINE


endef
# Function that can be $(call)ed to print each value on a new line
newlineprint	= $(NEWLINE)$(subst $(SPACE),$(NEWLINE),$(1))

all: core

core: $(BIN)
	@echo
	@echo Built $(BIN)
	@echo

run: $(BIN)
	@echo 
	@echo Running $(BIN) ...
	$(BIN)

# Create the BINDIR and BUILDDIR directories if they do not exist
$(BUILDDIR) $(BINDIR):
	@mkdir $@

# Link objects into BIN
$(BIN): $(OBJS) | $(BINDIR)
	$(info All sources:			$(call newlineprint,$(SRCS)))
	$(info All objects:   		$(call newlineprint,$(OBJS)))
	@mkdir -p $(dir $@)
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