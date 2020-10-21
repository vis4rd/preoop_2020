### preoop_2020

##### przydatne pliki

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
#ustawienie wersji CMake
cmake_minimum_required(VERSION 3.10)

#nazwa projektu
project(lab_ppo)

# dodanie pliku wykonywalnego
add_executable(Main main.cpp)

#w przypadku kilku plików źródłowych
#add_executable(Main main.cpp test.cpp files.cpp)

#ustawienie flag podczas kompilacji
set (CMAKE_CXX_FLAGS "-Wall -g")

# ustawienie standardu C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#definiowanie zmiennych
set(SOURCES main.cpp test.cpp files.cpp)
add_executable(Main ${SOURCES})
```

Caveat emptor.
