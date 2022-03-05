// Given m colors
// V nodes
// is it possible to color the graph such that no adjacent node is of same color
// using atmost m color
// Idea is to try coloring each node with m color
// if at the end graph is colored then return true else false
bool can_be_colored(int current_node, bool graph[101][101], int colored_nodes[], int total_nodes, int current_color) {
    // looping bcoz it is 2d graph to check all the edges to current node.
    for (int i = 0; i < total_nodes; i++) {
        // check if current color is already given to the adjacent color
        if (i != current_node and graph[i][current_node] and colored_nodes[i] == current_color) return false;
    }
    return true;
}

bool solve(int current_node, bool graph[101][101], int colored_nodes[], int max_colors, int total_nodes) {
    // if this is the last node+1 then already colored all the nodes.
    // as nodes are starting from 0 to n-1
    if (current_node == total_nodes) return true;
    // try coloring with each color
    for (int current_color = 1; current_color <= max_colors; current_color++) {
        if (can_be_colored(current_node, graph, colored_nodes, total_nodes, current_color)) {
            // mark the current color to the current node
            colored_nodes[current_node] = current_color;
            if (solve(current_node + 1, graph, colored_nodes, max_colors, total_nodes)) return true;
            // remove current color as ans is not found using current color
            // backtrack
            colored_nodes[current_node] = 0;
        }
    }
    // if not possible to color
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    // all entries are 0 hence use color more than 0, 0-> not colored
    int colored_nodes[V] = {0};
    return solve(0, graph, colored_nodes, m, V);
}