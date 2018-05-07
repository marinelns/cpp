PROG = Dvector PhilipsWaveModel WaveModel GeneriqueVector Ocean GerstnerWaveModel GerstnerWave Height main
INCLUDES =  Dvector.h PhilipsWaveModel.h WaveModel.h GeneriqueVector.h Ocean.h GerstnerWaveModel.h GerstnerWave.h Height.h main.h
OBJ = Dvector.o PhilipsWaveModel.o WaveModel.o GeneriqueVector.o Ocean.o GerstnerWaveModel.o GerstnerWave.o Height.o main.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
