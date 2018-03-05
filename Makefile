# Compiler
CC := g++

# Paths
SRCDIR := src
BUILDDIR := build
INCDIR := include
TARGET := bin/run

SRC := main.cpp product.cpp producer.cpp

OBJ := $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

CFLAGS := -g

$(TARGET): $(OBJ)
	@echo " Linking..."
	@echo " $(CC) %^ -o $(TARGET)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) -I $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
