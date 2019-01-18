# Makefile for Tuesday Doubles Project

# Compiler & Flags
CC := g++
CPPFLAGS := -std=c++11 -g

# Folders
ProjectPath := $(subst /Makefile,,$(abspath $(lastword $(MAKEFILE_LIST))))
HeaderFolder := $(ProjectPath)/Headers
ImplementationFolder := $(ProjectPath)/Implementations
MainSourceFolder := $(ProjectPath)/Source

BuildPath := $(ProjectPath)/Build
ObjectPath := $(BuildPath)/Objects
BinPath := $(BuildPath)/Bin

CPPFLAGS += -I $(HeaderFolder)

# Files
ObjExtension := .o
SrcExtension := .cpp

HeaderNames := $(basename $(notdir $(wildcard $(HeaderFolder)/*.h)))
ObjectNames := $(basename $(notdir $(wildcard $(ImplementationFolder)/*.cpp)))
ExecutableNames := $(basename $(notdir $(wildcard $(MainSourceFolder)/*.cpp)))

Objects := $(addsuffix $(ObjExtension),$(addprefix $(ObjectPath)/,$(ObjectNames)))
Executables := $(addprefix $(BinPath)/,$(ExecutableNames))

all: $(Executables)
#	@echo $(Objects)
#	@echo $(Executables)
#	@echo $(Objs)
# 	@echo $(MAKEFILE_LIST)
# 	@echo $(ProjectPath)
# # 	@echo $(HeaderFolder)
# # 	@echo $(MainSourceFolder)
# 	@echo $(ImplementationFolder)
# #	@echo $(Headers)
#	@echo $(Implementations)
# #	@echo $(MainSource)

# 	ls $(ImplementationFolder)


$(ObjectPath)/%.o: $(ImplementationFolder)/%.cpp init_build_dir
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(BinPath)/%: $(MainSourceFolder)/%.cpp $(Objects)
	@$(CC) $(CPPFLAGS) -o $@ $^

init_build_dir:
	@mkdir --parents $(ObjectPath)
	@mkdir --parents $(BinPath)

.PHONY: clean

clean: 
	@rm -f $(ObjectPath)/*.o $(Executables)