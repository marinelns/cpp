PROG = Dvector PhilipsWaveModel WaveModel GeneriqueVector Ocean GerstnerWaveModel GerstnerWave Height mainPhilips
INCLUDES =  Dvector.h PhilipsWaveModel.h WaveModel.h GeneriqueVector.h Ocean.h GerstnerWaveModel.h GerstnerWave.h Height.h mainPhilips.h
OBJ = Dvector.o PhilipsWaveModel.o WaveModel.o GeneriqueVector.o Ocean.o GerstnerWaveModel.o GerstnerWave.o Height.o mainPhilips.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
