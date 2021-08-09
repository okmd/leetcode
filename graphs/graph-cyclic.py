import unittest
from graph import Graph


class GraphCyclic(Graph):

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
        if not self.is_undirected():
            curr_stack_visited = [False]*self.nodes

        visited = [False]*self.nodes
        for i in range(self.nodes):
            if not visited[i]:
                if self.is_undirected():
                    if self._has_cycle_undirected(visited, i, -1):
                        return True
                else:
                    if self._has_cycle_directed(visited, curr_stack_visited, i):
                        return True
        return False
    
    # def _is_cyclic_coloring_helper(self, color, visited, curr):
    #     visited[curr] = True
    #     if color[curr] == 2:
    #         return True
        
    #     color[curr] = 1
    #     for i in self.get_adjList()[curr]:
    #         if color[i] == 1:
    #             color[i] = 2
    #         else:
    #             if self._is_cyclic_coloring_helper(color.copy(), visited, i):
    #                 return True
    #     return False
        
        
    
    # def is_cyclic_coloring(self):
    #     # 0->not visited[white], 1->visited[grey], 2->visited+processed[black]
    #     # grey is in function call stack
    #     color = [0]*self.get_nodes()
    #     visited = [False]*self.get_nodes()
    #     for i in range(self.get_nodes()):
    #         if not visited[i]:
    #             if self._is_cyclic_coloring_helper(color, visited, i):
    #                 return True
    #     return False
                


class TestGraphCyclic(unittest.TestCase):
    def test_forest_directed(self):
        g = GraphCyclic(5)
        edges = [(0, 1), (0, 2), (1, 2), (3, 4)]
        g.add_edges(edges)
        self.assertEqual(g.is_cyclic(), False,
                         msg="Directed cyclic forest failed ")
        g.add_edges([(4, 4)])
        self.assertEqual(g.is_cyclic(), True,
                         msg="Directed cyclic forest failed ")

    def test_forest_undirected(self):
        g = GraphCyclic(4, True)
        edges = [(0, 1), (0, 2)]
        g.add_edges(edges)
        self.assertEqual(g.is_cyclic(), False,
                         msg="Undirected forest cyclic failed ")
        g.add_edges([(3, 3)])
        self.assertEqual(g.is_cyclic(), True,
                         msg="Undirected forest cyclic failed ")

    def test_tree(self):
        g = GraphCyclic(4)
        edges = [(0, 1), (0, 2), (1, 2), (3, 0)]
        g.add_edges(edges)
        self.assertEqual(g.is_cyclic(), False,
                         msg="Directed tree cyclic failed ")
        g.add_edges([(2, 3)])
        self.assertEqual(g.is_cyclic(), True,
                         msg="Directed tree cyclic failed ")

    def test_tree_undirected(self):
        g = GraphCyclic(4, True)
        edges = [(0, 1), (0, 2), (3, 0)]
        g.add_edges(edges)
        self.assertEqual(g.is_cyclic(), False,
                         msg="Undirected tree cyclic failed ")
        g.add_edges([(1, 2), (2, 3)])
        self.assertEqual(g.is_cyclic(), True,
                         msg="Undirected tree cyclic failed ")


if __name__ == "__main__":
    unittest.main()
