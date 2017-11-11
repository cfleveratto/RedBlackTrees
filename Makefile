objects = useRBTree.o inputFunctions.o

testRBTree: $(objects)
	g++ $(objects) -o testRBTree

useRBTree.o: RBTree.h inputFunctions.h useRBTree.cpp
	g++ -c useRBTree.cpp

RBTree.h: RBNode.h constants.h

RBNode.h: constants.h

inputFunctions.o: constants.h RBTree.h inputFunctions.h inputFunctions.cpp
	g++ -c inputFunctions.cpp

clean:
	rm *~ $(objects) testRBTree
