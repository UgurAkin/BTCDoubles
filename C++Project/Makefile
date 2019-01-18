# Makefile for Tuesday Doubles Project

# Compiler & Flags
CC := g++
CPPFLAGS := 

# Folders
ProjectPath := $(subst /Makefile,,$(abspath $(lastword $(MAKEFILE_LIST))))
HeaderFolder := $(ProjectPath)/Headers
ImplementationFolder := $(ProjectPath)/Implementations
MainSourceFolder := $(ProjectPath)/MainSource

BuildPath := $(ProjectPath)/Build
ObjectPath := $(BuildPath)/Objects


# Files
ObjExtension := .o
SrcExtension := .cpp

HeaderNames := $(basename $(notdir $(wildcard $(HeaderFolder)/*.h)))
ObjectNames := $(basename $(notdir $(wildcard $(ImplementationFolder)/*.cpp)))
MainSourceName := main

Exe := $(ProjectPath)/main;

Objects := $(addsuffix $(ObjExtension),$(addprefix $(ObjectPath)/,$(ObjectNames)))

all: main
#	@echo $(Objects)
#	@echo $(Exe)
#	@echo $(Objs)
# 	@echo $(MAKEFILE_LIST)
# 	@echo $(ProjectPath)
# # 	@echo $(HeaderFolder)
# # 	@echo $(MainSourceFolder)
# 	@echo $(ImplementationFolder)
# #	@echo $(Headers)
	@echo $(Implementations)
# #	@echo $(MainSource)

# 	ls $(ImplementationFolder)


$(ObjectPath)/%.o: $(ImplementationFolder)/%.cpp init_build_dir
	$(CC) $(CPPFLAGS) -c -o $@ $<

main: $(Objects)
	$(CC) $(CPPFLAGS) -o $@ $<

init_build_dir:
	mkdir --parents $(ObjectPath)

.PHONY: clean

clean: 
	rm -f $(ObjectPath)/*.o $(Exe)
