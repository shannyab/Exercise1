/*
323858324
shannya08@gmail.com
 */
#pragma once
#include <vector>

namespace ariel
{
    class Graph
    {
        public:
            std::vector<std::vector<int>> _graph;
            void loadGraph(std::vector<std::vector<int>> graph);

            void printGraph() const;


            std::size_t size() const {
                return _graph.size();
            }
          

        private:
            void validateGraph() const;
            
    }; 

}; 