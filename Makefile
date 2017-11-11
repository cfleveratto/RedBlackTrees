objects = useRBTree.o inputFunctions.o useRBTree.o

testRBTree: $(objects)
	g++ $(objects) -o testRBTree

useRBTree.o: RBTree.h inputFunctions.h useRBTree.cpp
	g++ -c useRBTree.cpp

RBTree.h: RBNode.h

inputFunctions.o: RBTree.h inputFunctions.h inputFunctions.cpp
	g++ -c inputFunctions.cpp

clean:
	rm *~ $(objects) testRBTree
