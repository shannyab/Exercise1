/*
323858324
shannya08@gmail.com
 */
#include "Graph.hpp"
#include <iostream>

namespace ariel
{
    void Graph::loadGraph(std::vector<std::vector<int>> graph)
    {
        // Clear the graph before loading the new one.
        this->_graph.clear();

        // Copy the new graph.
        for (size_t i = 0; i < graph.size(); i++)
        {
            std::vector<int> row;
            for (size_t j = 0; j < graph[i].size(); j++)
            {
                row.push_back(graph[i][j]);
            }
            this->_graph.push_back(row);
        }

        
        this->validateGraph();
    }

    void Graph::printGraph() const
    {
        size_t vertices = this->_graph.size();
        size_t edges = 0;
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        std::cout << "Graph with " << vertices << " vertices and " << edges << " edges." << std::endl;
    }

    void Graph::validateGraph() const
    {
        size_t vertices = this->_graph.size();
        for (size_t i = 0; i < vertices; i++)
        {
            if (this->_graph[i].size() != vertices)
            {
                throw std::invalid_argument("Invalid graph.");
            }
        }
    }
}; 