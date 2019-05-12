# ShortestPath_C
This is Project Implements a modified version of shortest path algorithm in (C language)

Details of the Project:

* A circuit is given as (n * m) character matrix of squares where there are k components to be connected to each other. Each component covers one unit square.

* Given a circuit, the  goal is to find wire routes connecting k components on the circuit with the minimum sum of lengths of the routes.

* In the matrix representing a circuit:

  a)"\*" squares are blocked squares 
  b)"0" squares are available to route a wire.
  c)The number i represents the ith component.

* All components should be connected where there is a path between every pair of components, but those paths cannot be crossed. A path consists of squares which are horizontally or vertically adjacent.

* The first line of the input represents the size of the matrix (n,m).

```
* Sample Input:
4 4
0 0 0 3
0 * 0 *
0 1 0 0
2 0 * 0
```
```
* Sample Output:
1,2:   (3 ,2) ,(3 ,1) ,(4 ,1)
1,3:   (3 ,2) ,(3 ,3) ,(2 ,3) ,(1 ,3) ,(1 ,4)
```
