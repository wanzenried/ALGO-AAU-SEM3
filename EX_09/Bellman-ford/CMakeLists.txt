SET(SOURCES
    bellman-ford.cpp
    ../graph/graph.cpp
)

add_executable(Bellman-ford ${SOURCES})
target_include_directories(Bellman-ford PRIVATE
    ../graph
)