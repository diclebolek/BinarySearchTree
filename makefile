# Default targets
# Default targets
all: compile link run

# Compilation step
compile:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/ikiliAramaAgaci.cpp -o ./lib/ikiliAramaAgaci.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o

# Linking step
link:
	g++ ./lib/main.o ./lib/ikiliAramaAgaci.o ./lib/Dugum.o -o ./bin/BinarySearchTree

# Running step
run:
	./bin/BinarySearchTree

# Cleaning step
clean:
	del /Q .\lib\*.o
	del /Q .\bin\BinarySearchTree

