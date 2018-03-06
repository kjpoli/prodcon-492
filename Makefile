# Compiler
CC := g++

# Paths
SRCDIR := src
BUILDDIR := build
INCDIR := include
TARGET := bin/run

# Retrieve all files in SRCDIR with cpp extensions
SRC := $(shell find $(SRCDIR) -type f -name *.cpp)

OBJ := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRC:.cpp=.o))

CFLAGS := -g

$(TARGET): $(OBJ)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $< -lpthread"; $(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $< -lpthread

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
