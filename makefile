###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS235
# Author:
#     Daniel Perez, Jamie Hurd, Benjamin Dyas
# Summary:
#     This program contains the implementation of the map
#		project, which requires the calling of BST members
#		to affect the successful counting of unique chars/
#		words.
#     Supporting classes like iterators, nodes and count are
#     also defined.
#     RED BLACK BALANCING WAS FINISHED FOR THIS WEEK
# Time:
#     Pair programming: 06 hours
#     Daniel:           06 hours
#     Benjamin:         06 hours
#	  Jamie:             06 hours
# The most difficult part:
#     Daniel:   The most difficult part was keeping track of 
#               pointers since the map iterator is to a great
#               measure a shell for the underlying BST. In
#               addition, finishing the remaining case of 
#               red-black tree balancing took a decent chunk of
#               time: keeping track of the pointers was the
#               culprit.
#	   Benjamin: The most difficult part for me was working
#               through the [] operator. I was confused with the
#               UML funcation name access. It turned out that
#               they were the same thing and we were able to
#               implement the operator correctly.
#	   Jamie:    The most difficult part entailed preparing the
#				    access operators and knowing how best to 
#				    call the bst functions necessary to make
#				    the magic happen with map.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g
