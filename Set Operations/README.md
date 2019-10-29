Program will simulate set operations using arrays. 
Program will display the following menu to perform set operations:
0. Input sets 
1. Swap sets
2. Find intersection
3. Shift sets
4. Find Union
5. Find a plateau 
6. Quit
Enter your choice (0,1,2,3,4,5,6):

Once user chooses the required task, operation will be performed and results will be displayed. Program will have the following functions:
inputSets(): Input set elements as columns of a 10x10 integer array and returns it  to the calling function.

swapSets(): receives a 2d integer array, its size and two column index specifying the sets to process as parameters. It will swap the sets located at the columns required and return the updated 2d array.  

findIntersection(): receives a 2d integer array, its size and two column index specifying the sets to process as parameters. It will return 1d array that holds the intersection of two sets.

shiftSets(): receives a 2d integer array, its size. It inputs n from user and shifts the columns n times to right.  It will return the updated 2d array.

findUnion(): receives a 2d integer array, its size and two column index specifying the sets to process as parameters. It will return another array that holds the union of two sets. (Note: Each element of the new array must be distinct)

