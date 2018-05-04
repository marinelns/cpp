PROG = Dvector PhilipsWaveModel WaveModel GeneriqueVector Ocean
INCLUDES =  Dvector.h PhilipsWaveModel.h WaveModel.h GeneriqueVector.h Ocean.h
OBJ = Dvector.o PhilipsWaveModel.o WaveModel.o GeneriqueVector.o Ocean.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
