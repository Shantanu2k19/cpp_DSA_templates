cycle detection:
directed graph: dfs with saving prevPath and visited array
undirected graph: df with parent 

DISTANCE 

dijkstras : for both directed and undirected, but not for -ve edges  TC: ElogV
<pq, insert and take out least dis, create dis array >
for cycle detection, dfs with saving path 

bellman ford: shortest path like dijkstras, but works with negative edges as well (not negative weight cycle) TC:EV
<do v-1 relaxation>

floyd warshal: shortest path bw all nodes, for negative edges, directed and undirected graphs TC: V^3
<got for a to b via every node, 3 loops>


MST 
kruskals algo: start with shortest edges, and create mst, check if no cycle is formed using disjoint set. TC:ElogE(sorting)+E@(v)+E@(v)(union and findPar)=> ElogE

prims algo : use pq to store all edges, use visited array for vertices, keep adding nodes in mst 
TC: ElogV  (logV+logV)*E, pushing popping from pq, processing each edge 


Topological sort : 
kahns algo: directed acyclic graph
<use queue, create indegree of each element, put the ones with 0 indeg in queue, popping the queue, push the 
nodes with indegree 0 back into queue>
TC: O(V+E)

 