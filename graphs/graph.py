from collections import defaultdict
from queue import Queue
import unittest


class Graph:
    def __init__(self, n, undirected=False):
        self.nodes = n
        # return [] as default value when key is not present
        self.adjList = defaultdict(list)
        self.__un_directed = undirected

    def add_edges(self, edge_list):
        for u, v in edge_list:
            self.adjList[u].append(v)
            if self.__un_directed:
                self.adjList[v].append(u)

    def _dfs_helper(self, visited, i, dfs_answer):
        visited[i] = True
        dfs_answer.append(i)
        for j in self.adjList[i]:
            if not visited[j]:
                self._dfs_helper(visited, j, dfs_answer)

    def dfs(self):
        visited = [False]*self.nodes
        answer = []
        # call for each node otherwise it may not work for forest, more than one tree.
        for i in range(self.nodes):
            if not visited[i]:
                self._dfs_helper(visited, i, answer)
        return answer

    def _bfs_helper(self, visited, i, bfs_answer):
        Q = Queue()
        visited[i] = True
        Q.put(i)
        while Q.qsize():
            curr = Q.get()
            bfs_answer.append(curr)
            for j in self.adjList[curr]:
                if not visited[j]:
                    Q.put(j)
                    visited[j] = True

    def bfs(self):
        visited = [False]*self.nodes
        answer = []
        # call for each node otherwise it may not work for forest, more than one tree.
        for i in range(self.nodes):
            if not visited[i]:
                self._bfs_helper(visited, i, answer)
        return answer

    def _has_cycle_undirected(self, visited, curr, parent):
        visited[curr] = True
        for i in self.adjList[curr]:
            if not visited[i]:
                if self._has_cycle_undirected(visited, i, curr):
                    return True
            elif i != parent:
                return True
        return False
    def _has_cycle_directed(self, visited, curr_stack_visited, curr):
        visited[curr] = True
        curr_stack_visited[curr] = True
        for i in self.adjList[curr]:
            if not visited[i]:
                if self._has_cycle_directed(visited, curr_stack_visited, i):
                    return True
            elif curr_stack_visited[i]:
                return True
        curr_stack_visited[curr] = False
        return False
                

    def is_cyclic(self):
        if not self.__un_directed:
            curr_stack_visited = [False]*self.nodes
            
        visited = [False]*self.nodes
        for i in range(self.nodes):
            if not visited[i]:
                if self.__un_directed:
                    if self._has_cycle_undirected(visited, i, -1):
                        return True
                else:
                    if self._has_cycle_directed(visited, curr_stack_visited, i):
                        return True
        return False


class TeshGraph(unittest.TestCase):
    def test_forest_directed(self):
        g = Graph(5)
        edges = [(0, 1), (0, 2), (1, 2), (3, 4), (4, 4)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3, 4], msg="DFS Directed Forest Failed")
        self.assertEqual(g.bfs(), [0, 1, 2, 3, 4], msg="BFS Directed Forest Failed")

    def test_forest_undirected(self):
        g = Graph(4, True)
        edges = [(0, 1), (0, 2), (3, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3], msg="DFS Undirected Forest Failed")
        self.assertEqual(g.bfs(), [0, 1, 2, 3], msg="BFS Undirected Forest Failed")
        self.assertEqual(g.is_cyclic(), True, msg="Undirected cyclic failed ")

    def test_tree(self):
        g = Graph(4)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3], msg="DFS Tree Failed")
        self.assertEqual(g.bfs(), [0, 1, 2, 3], msg="BFS Tree Failed")
        self.assertEqual(g.is_cyclic(), True, msg="Directed cyclic failed ")

    def test_tree_undirected(self):
        g = Graph(4, True)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3],
                         msg="DFS Undirected Tree Failed")
        self.assertEqual(g.bfs(), [0, 1, 2, 3],
                         msg="BFS Undirected Tree Failed")


if __name__ == "__main__":
    unittest.main()
