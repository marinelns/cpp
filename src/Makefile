PROG = Height Dvector WaveModel GerstnerWave GerstnerWaveModel
INCLUDES = Height.h Dvector.h WaveModel.h GerstnerWave.h GerstnerWaveModel.h
OBJ = Height.o Dvector.o WaveModel.o GerstnerWave.o GerstnerWaveModel.o
CXX = g++
CXXFLAGS = -Wall

all: $(PROG)

clean:
	rm -r $(OBJ)

$(PROG):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:%.cxx
	$(CXX) -C $(CXXFLAGS) -o $@ $<
