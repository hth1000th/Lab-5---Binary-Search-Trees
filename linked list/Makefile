all: bst.c tree_traversal.c
	gcc -o main bst.c tree_traversal.c -I .

run:
	./main

clean:
	rm -f main
	rm -f t

test: test_bst.c tree_traversal.c
	gcc -o t test_bst.c tree_traversal.c -I .
	./t
	rm -f t
