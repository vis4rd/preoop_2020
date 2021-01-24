## Podstawy Programowania Obiektowego

Kod napisany na laby u EOM. Korzystalismy z serwisu `repl.it`.
Semestr 3, rok 2020.

### przydatne pliki

`clean.sh`:
```bash
#!/bin/bash
# Czyszczenie wszystkich plikow z wyjatkiem pliku skryptu i Makefile
read -p "Usunac wszystkie pliki? (t/n): " answer
shopt -s extglob;
if [ "$answer" = "t" ]; 
  then rm -rv !(@(clean.sh|Makefile))
fi
```

`Makefile`:
```make
CXX = g++
EXEC = main
CXXFLAGS = -std=c++14 -Wall -pedantic
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(EXEC) run

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -rf *.o $(EXEC)

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean run check
```

`CMakeLists.txt`:
```
cmake_minimum_required(VERSION 3.10)

PROJECT(cpp_project)

# Setting up the C++ compilation flags
SET(CMAKE_CXX_FLAGS "-Wall -g -pedantic")

# Setting up C++ standard
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_COLOR_MAKEFILE True)

# Searching for all header files in directory tree
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_dir_list)

LIST(LENGTH header_dir_list header_dir_list_count)

IF(header_dir_list_count GREATER 0)
	MESSAGE(STATUS "[INFO] Found ${header_dir_list_count} header directories: ")
	MESSAGE(STATUS "[INFO] ${header_dir_list}")
ELSE()
	MESSAGE(STATUS "[INFO] Found ${header_dir_list_count} header directories")
ENDIF()

INCLUDE_DIRECTORIES(${header_dir_list}) # Recursive

# Gathering all .cpp files required to compile the program
FILE(GLOB_RECURSE SOURCES "*.cpp")

# This line is actually very cursed, but essentially it removes cmake generated .cpp file
# containing repetition of main() function, which allows successfull compilation
LIST(REMOVE_AT SOURCES 0)

# Adding obtained .cpp files to the project
add_executable (output ${SOURCES})

# The end of CMakeLists.txt file
```

Caveat emptor.
