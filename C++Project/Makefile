# Makefile for Tuesday Doubles Project

# Compiler & Flags
CC := g++
CPPFLAGS := ""

# Folders
ProjectPath := $(abspath $(lastword $(MAKEFILE_LIST)))
HeaderFolder := $(ProjectPath)/Headers
ImplementationFolder := $(ProjectPath)/Implementations
SourceFolder := $(ProjectPath)/Source
BuildFolder := $(ProjectPath)/Build

# Files
Headers = $(wildcard $(HeaderFolder)/*.h)
Implementations = $(wildcard $(ImplementationFolder)/*.cpp)
Source = $(SourceFolder)/main.cpp


all: headers source
# 	echo $(HeaderFolder)
# 	echo $(SourceFolder)
# 	echo $(ImplementationFolder)
#	echo $(Headers)
#	echo $(Implementations)
	echo $(Source)

headers:
	echo "hi im headers"
source:
	echo "hi im source"
