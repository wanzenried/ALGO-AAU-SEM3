SET(SOURCES
    dijkstra.cpp
    ../graph/graph.cpp
)

add_executable(Dijkstra ${SOURCES})
target_include_directories(Dijkstra PRIVATE
    ../graph
)