/*
323858324
shannya08@gmail.com
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object g.
    cout << "first graph " << endl;

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."


    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object g.
    cout << "second graph " << endl;

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object g.
    cout << "third graph " << endl;

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl;  // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    cout << "fourth graph " << endl;
    try
    {
        g.loadGraph(graph4); // Load the graph to the object g.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph"
    }
// 4x4 matrix that represents a connected weighted graph.
    vector<vector<int>> graph5 = {
    {0, 1, 0, 0},
    {0, 0, -2, 0},
    {0, 0, 0, 3},
    {4, 0, 0, 0}};
    g.loadGraph(graph5); // Load the graph to the object g.
    cout << "fifth graph " << endl;

    g.printGraph();                                    // Should print: "Graph with 4 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 3) << endl; // Should print: 0->1->2->3.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print:"The cycle is: 0->1->2->3->0".
    cout << "Negative cycle found: " << Algorithms::negativeCycle(g) << endl; // Should print: "Negative cycle found :The graph does not contain negative cycle".

    // 5x5 matrix that represents a connected weighted graph.
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph6); // Load the graph to the object g.
    cout << "sixth graph " << endl;

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl;  // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << "Negative cycle found: " << Algorithms::negativeCycle(g) << endl; // Should print: "Negative cycle found :The graph does not contain negative cycle"
// 5x5 matrix that represents a connected weighted graph with negative cycle.
    vector<vector<int>> graph7 = {
    {0, 2, 0, 0, 0},
        {0, 0, -3, 0, 0},
        {0, 0, 0, 1, 0},
        {-4, 0, 0, 0, 5},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph7); // Load the graph to the object g.
    cout << "seventh graph " << endl;
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 5 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl;  // Should print: "Negative cycle detected in the path"
    cout << Algorithms::isContainsCycle(g) << endl;   //Should print:"The cycle is: 0->1->2->3->0".
    cout << "Negative cycle found: " << Algorithms::negativeCycle(g) << endl;//Should print: "Negative cycle found :The graph contains negative cycle".
    }

