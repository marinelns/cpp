project(lib)
set(SOURCES Dvector.cpp GeneriqueVector.cpp GerstnerWave.cpp GerstnerWaveModel.cpp Height.cpp Ocean.cpp
PhilipsWaveModel.cpp WaveModel.cpp)
add_library(lib ${SOURCES})
