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

CPPFLAGS += -I $(HeaderFolder)

# Files
ObjExtension := .o
SrcExtension := .cpp

HeaderNames := $(basename $(notdir $(wildcard $(HeaderFolder)/*.h)))
ObjectNames := $(basename $(notdir $(wildcard $(ImplementationFolder)/*.cpp)))
MainSourceName := main

Exe := $(ProjectPath)/$(MainSourceName);

Objects := $(addsuffix $(ObjExtension),$(addprefix $(ObjectPath)/,$(ObjectNames)))
MainSource := $(addsuffix $(SrcExtension),$(addprefix $(MainSourceFolder)/,$(MainSourceName)))

all: $(Exe)
#	@echo $(Objects)
#	@echo $(Exe)
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

# $(Exe): $(Objects)
$(ProjectPath)/$(MainSourceName): $(Objects) $(MainSource)
	@$(CC) $(CPPFLAGS) -o $@ $^

init_build_dir:
	@mkdir --parents $(ObjectPath)

.PHONY: clean

clean: 
	@rm -f $(ObjectPath)/*.o $(Exe)
