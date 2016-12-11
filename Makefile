# treat all files as "secondary" so no intermediate files will be removed by make itself after the building process (from http://stackoverflow.com/a/29114706)
.SECONDARY:

# build structure paths
PROJECT_NAME=scratch-code
PROJECT_BIN_DIR=bin
PROJECT_DEP_DIR=dep
PROJECT_EXT_DIR=ext
PROJECT_GEN_DIR=gen
PROJECT_INCLUDE_DIR=include
PROJECT_OBJ_DIR=obj
PROJECT_SRC_DIR=src
PROJECT_BINARY_RPATH=\$${ORIGIN}/../lib

# lists of own files (not the *.l and *.ypp ones for flex and bison!)
CPP_FILES=$(wildcard $(PROJECT_SRC_DIR)/*.cpp)
OBJ_FILES=$(addprefix $(PROJECT_OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)) $(PROJECT_NAME).lex.o $(PROJECT_NAME).tab.o)
DEP_FILES=$(addprefix $(PROJECT_DEP_DIR)/,$(notdir $(CPP_FILES:.cpp=.d)))
EXECUTABLE=$(PROJECT_BIN_DIR)/$(PROJECT_NAME)

# include and library paths and needed libraries
# -isystem flag to disable warnings from specific include locations, from http://stackoverflow.com/a/6321926
INCLUDE_PATHS=-I$(PROJECT_INCLUDE_DIR) -I$(PROJECT_GEN_DIR) -I$(PROJECT_EXT_DIR)/scratch-code-ast/include -isystem $(PROJECT_EXT_DIR)/boost/include -isystem $(PROJECT_EXT_DIR)/rapidjson/include -isystem $(PROJECT_EXT_DIR)/ziplib/include -isystem $(PROJECT_EXT_DIR)/libpng/include -isystem $(PROJECT_EXT_DIR)/openssl/include
LIBRARY_PATHS=-L$(PROJECT_EXT_DIR)/scratch-code-ast/lib -L$(PROJECT_EXT_DIR)/ziplib/lib -L$(PROJECT_EXT_DIR)/boost/lib -L$(PROJECT_EXT_DIR)/libpng/lib -L$(PROJECT_EXT_DIR)/openssl/lib
LIBRARIES=-lcrypto -lboost_filesystem -lboost_system -lpng -lzip -lfl -lscratch-code-ast

# names and options for used programs
CXX=g++
CXXFLAGS=-g -std=c++14 -Wall $(INCLUDE_PATHS)
CXXFLAGS_FLEXBISON=-g -std=c++14 -Wall -Wno-unused-function -Wno-sign-compare $(INCLUDE_PATHS)
LDFLAGS=-Wall $(LIBRARY_PATHS) $(LIBRARIES) -Wl,-rpath,$(PROJECT_BINARY_RPATH)
FLEX=flex
FLEXFLAGS=
BISON=bison
BISONFLAGS=-v
DISCARD_OUTPUT=/dev/null
DIR_GUARD=@mkdir -p $(@D)



all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(DIR_GUARD)
	$(CXX) $^ -o $@ $(LDFLAGS)

clean: clean_gen
	rm -f $(EXECUTABLE) 2>&1 > $(DISCARD_OUTPUT)

clean_gen:
	rm -f $(PROJECT_GEN_DIR)/* $(PROJECT_OBJ_DIR)/* $(PROJECT_DEP_DIR)/* 2>&1 > $(DISCARD_OUTPUT)



$(PROJECT_DEP_DIR)/%.d: $(PROJECT_SRC_DIR)/%.cpp $(PROJECT_INCLUDE_DIR)/%.hpp
	$(DIR_GUARD)
	$(CXX) -E -MM -MP -MG -MT $(PROJECT_OBJ_DIR)/$(basename $(notdir $@)).o -MF $@ $(CXXFLAGS) $< > $(DISCARD_OUTPUT)

$(PROJECT_GEN_DIR)/%.lex.cpp: $(PROJECT_SRC_DIR)/%.l $(PROJECT_GEN_DIR)/%.tab.hpp
	$(DIR_GUARD)
	$(FLEX) $(FLEXFLAGS) -o $@ $<

$(PROJECT_GEN_DIR)/%.tab.cpp $(PROJECT_GEN_DIR)/%.tab.hpp: $(PROJECT_SRC_DIR)/%.ypp
	$(DIR_GUARD)
	$(BISON) $(BISONFLAGS) -d $< -o $(PROJECT_GEN_DIR)/$*.tab.cpp

$(PROJECT_OBJ_DIR)/%.o: $(PROJECT_GEN_DIR)/%.cpp
	$(DIR_GUARD)
	$(CXX) -c $(CXXFLAGS_FLEXBISON) -o $@ $<

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), clean_gen)
-include $(DEP_FILES)
endif
endif



.SECONDEXPANSION:
$(PROJECT_OBJ_DIR)/%.o: $(PROJECT_SRC_DIR)/%.cpp
	$(DIR_GUARD)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: clean clean_gen
