# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

PROJECT("SPLCUDA" LANGUAGES CUDA CXX)

INCLUDE_DIRECTORIES(
	include/ 
)

# Schließen Sie Unterprojekte ein.
add_subdirectory ("doc")
add_subdirectory ("tests")
