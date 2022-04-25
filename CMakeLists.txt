# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

project ("SPL")
INCLUDE_DIRECTORIES(
	include/  
)

# Schließen Sie Unterprojekte ein.
add_subdirectory ("SPL")
