CXX      = g++
CXXFLAGS = -O3 -flto -std=c++17 -finline-functions -funswitch-loops -march=native -mtune=native

.PHONY: all local member

all: local member

local:
	$(CXX) -o local -Ilocal_hdr $(CXXFLAGS) GeneratedStubExample.cpp

member:
	$(CXX) -o member -Imember_hdr $(CXXFLAGS) GeneratedStubExample.cpp
