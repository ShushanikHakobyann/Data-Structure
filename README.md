Flight Connection Optimizer

Live Demo

https://shushanikhakobyann.github.io/Data-Structure/


Project Description

This project is a Flight Connection Optimizer application built using C++ and graph-based algorithms. The system models a flight network as a weighted directed graph, where airports are represented as nodes and flight routes as edges with associated cost and duration.

The application allows users to find the cheapest and fastest routes between airports, explore reachable destinations within a limited number of connections, and identify critical airports that impact network connectivity.

Project Objectives

~To model a flight network as a weighted directed graph

~To load and process real-world-inspired flight data from a CSV file

~To implement Dijkstra’s algorithm for shortest path calculation (cost and duration)

~To implement BFS to explore reachable airports within K connections

~To detect critical airports affecting network connectivity

~To handle edge cases such as invalid input and missing routes

Data Structures & Algorithms Used
Data Structures

~Adjacency List (graph representation of airports and routes)

~Priority Queue (used in Dijkstra’s algorithm)

~Queue (used in BFS traversal)

~Set / Map (for visited nodes and distance tracking)

Algorithms

~Dijkstra’s Algorithm (Cheapest and Fastest Route Finding)

~Breadth-First Search (Reachability within K connections)

~Depth-First Search (Used in articulation points detection)

~Articulation Points Detection (Critical airport identification)

Overall Approach

The flight network is represented as a graph using an adjacency list. Flight data is loaded from a CSV file, where each row defines a connection between two airports along with cost and duration.

Dijkstra’s algorithm is applied twice to compute optimal routes:

Based on cost (cheapest route)
Based on duration (fastest route)

BFS is used to determine all reachable airports within a limited number of connections. Additionally, a DFS-based approach is used to detect articulation points, identifying airports that are critical to maintaining connectivity in the network.

The application runs as a command-line interface (CLI), allowing users to interactively select operations and view results.

Team Members

Shushanik Hakobyan
Elen Ghazaryan

Contributions

👩‍💻 Shushanik Hakobyan

~Implemented core graph structure

~Implemented Dijkstra’s algorithm (cost & duration)

~Implemented BFS for K connections

~Conducted research and prepared documentation

~Handled edge cases and algorithm logic

👩‍💼 Elen Ghazaryan

~Managed project coordination and workflow

~Organized development process and task distribution

~Supported testing and validation of functionality

~Contributed to system structure and final integration

~Assisted in documentation and presentation

Technologies Used

C++

Standard Template Library (STL)

CSV file handling

Command-Line Interface (CLI)
