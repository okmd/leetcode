import unittest
from graph import Graph


class GraphDFS(Graph):

    def _dfs_helper(self, visited, i, dfs_answer):
        visited[i] = True
        dfs_answer.append(i)
        for j in self.get_adjList()[i]:
            if not visited[j]:
                self._dfs_helper(visited, j, dfs_answer)

    def dfs(self):
        visited = [False]*self.get_nodes()
        answer = []
        # call for each node otherwise it may not work for forest, more than one tree.
        for i in range(self.get_nodes()):
            if not visited[i]:
                self._dfs_helper(visited, i, answer)
        return answer


class TeshGraphDFS(unittest.TestCase):
    def test_forest_directed(self):
        g = GraphDFS(5)
        edges = [(0, 1), (0, 2), (1, 2), (3, 4), (4, 4)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3, 4],
                         msg="DFS Directed Forest Failed")

    def test_forest_undirected(self):
        g = GraphDFS(4, True)
        edges = [(0, 1), (0, 2), (3, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3],
                         msg="DFS Undirected Forest Failed")

    def test_tree(self):
        g = GraphDFS(4)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3], msg="DFS Tree Failed")

    def test_tree_undirected(self):
        g = GraphDFS(4, True)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0), (2, 3)]
        g.add_edges(edges)
        self.assertEqual(g.dfs(), [0, 1, 2, 3],
                         msg="DFS Undirected Tree Failed")


if __name__ == "__main__":
    unittest.main()
