# CMakeList.txt: CMake-Projekt für "SPL". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (SPL "include/SPL.h" "tests/vector/SPL.cpp")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
