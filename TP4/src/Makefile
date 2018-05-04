PROG = Dvector Height PhilipsWaveModel
INCLUDES =  Dvector.h Height.h PhilipsWaveModel.h
OBJ = Dvector.o Height.o PhilipsWaveModel.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
