project(libOcean)
set(SOURCES Dvector.cpp
            GeneriqueVector.cpp
            GerstnerWave.cpp
            GerstnerWaveModel.cpp
            Height.cpp
            Ocean.cpp
            PhilipsWaveModel.cpp
            WaveModel.cpp
            camera.cxx
            window.cxx
            main.cxx
            main.cpp)
add_library(libOcean ${SOURCES})
