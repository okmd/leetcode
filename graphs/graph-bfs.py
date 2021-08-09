from queue import Queue
import unittest
from graph import Graph


class GraphBFS(Graph):

    def _bfs_helper(self, visited, i, bfs_answer):
        Q = Queue()
        visited[i] = True
        Q.put(i)
        while Q.qsize():
            curr = Q.get()
            bfs_answer.append(curr)
            for j in self.get_adjList()[curr]:
                if not visited[j]:
                    Q.put(j)
                    visited[j] = True

    def bfs(self):
        visited = [False]*self.get_nodes()
        answer = []
        # call for each node otherwise it may not work for forest, more than one tree.
        for i in range(self.get_nodes()):
            if not visited[i]:
                self._bfs_helper(visited, i, answer)
        return answer


class TestGraphBFS(unittest.TestCase):
    def test_forest_directed(self):
        g = GraphBFS(5)
        edges = [(0, 1), (0, 2), (1, 2), (3, 4), (4, 4)]
        g.add_edges(edges)
        self.assertEqual(g.bfs(), [0, 1, 2, 3, 4],
                         msg="BFS Directed Forest Failed")

    def test_forest_undirected(self):
        g = GraphBFS(4, True)
        edges = [(0, 1), (0, 2), (3, 3)]
        g.add_edges(edges)
        self.assertEqual(g.bfs(), [0, 1, 2, 3],
                         msg="BFS Undirected Forest Failed")

    def test_tree(self):
        g = GraphBFS(4)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.bfs(), [0, 1, 2, 3], msg="BFS Tree Failed")

    def test_tree_undirected(self):
        g = GraphBFS(4, True)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.bfs(), [0, 1, 2, 3],
                         msg="BFS Undirected Tree Failed")


if __name__ == "__main__":
    unittest.main()
