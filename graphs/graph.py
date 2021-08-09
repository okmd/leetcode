from collections import defaultdict
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

    def is_undirected(self):
        return self.__un_directed

    def get_adjList(self):
        return self.adjList

    def get_nodes(self):
        return self.nodes


class TestGraph(unittest.TestCase):
    def test_undirected(self):
        g = Graph(4, True)
        g.add_edges([(0, 1), (2, 3)])
        self.assertDictEqual(g.get_adjList(), dict(
            [(0, [1]), (2, [3]), (1, [0]), (3, [2])]))

    def test_directed(self):
        g = Graph(4)
        g.add_edges([(0, 1), (2, 3)])
        self.assertDictEqual(g.get_adjList(), dict([(0, [1]), (2, [3])]))


if __name__ == "__main__":
    unittest.main()
