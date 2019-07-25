# TSP
The TSP is one of the most important problems in the science of computer complexity and theory of graphs, the statement is as follows: a salesman has arrived in a seller where there is cities. The salesman wants to go to each city only once, in the shortest time.Despite the simplicity of the presentation of the question, it turned out that this question is one of the questions that do not know an optimal and efficient algorithm at the same time.
We propose two methods of resolution :

1-trivial algorithm:
This method is based on browsing of a search tree. In a path of this tree, the first node represents the city of departure, 
its successor the second city visited, then the third city visited, etc. At each stage of the algorithm, we create as many nodes 
as there are cities to visit. At each node, the choice is to select the next city to visit from the remaining cities.

2-Glutton Algorithm:
The trivial algorithm gives an optimal solution but in an exponential complexity. There is not an efficient algorithm that gives an optimal solution for this problem, but there are heuristics and algorithms that give acceptable and approximate solutions in an efficient way, This glutton algorithm works on all the edges of the complete graph. An edge is chosen if and only if it does not form a cycle (unless one reaches the last vertex) and it is not the third edge incident to a vertex in the circuit.
