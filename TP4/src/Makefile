PROG = Dvector GerstnerWaveModel
INCLUDES =  Dvector.h GerstnerWaveModel.h
OBJ = Dvector.o GerstnerWaveModel.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
