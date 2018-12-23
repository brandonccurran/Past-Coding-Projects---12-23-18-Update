This Project is an implementation of the C++ functions malloc and free. Documentation for these functions can be found below.
(http://www.cplusplus.com/reference/cstdlib/malloc/)
(http://www.cplusplus.com/reference/cstdlib/free/)

While the frame of the project was created by Timothy Richards (https://www.cics.umass.edu/faculty/directory/richards_tim), I implemented the following functions in the my_malloc.cpp file:

 - find_free
	Finds a node on the free list that has enough available memory to
	allocate to a calling program. This function uses the "first-fit"
	algorithm to locate a free node.


 - split
	The job of this function is to take a given free_node found from
	find_free` and split it according to the number of bytes to allocate.
	In doing so, it will adjust the size and next pointer of the `free_block`
	as well as the `previous` node to properly adjust the free list.


 - my_malloc
	Returns a pointer to a region of memory having at least the request `size` bytes.



 - coalesce
	This function will only coalesce nodes starting with `free_block`. It will
	not handle coalescing of previous nodes (we don't have previous pointers!).


 - my_free
	Frees a given region of memory back to the free list.


All credit for starter code and project documentation belongs to Tim Richards
https://www.cics.umass.edu/faculty/directory/richards_tim