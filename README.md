# Strongly Connected Components (SCC) in Directed Graphs

## **Project Overview**
This project implements an algorithm to compute **Strongly Connected Components (SCCs)** in a given **directed graph** using **Depth First Search (DFS)**. The implementation is applied to a real-world dataset from **Google Web Graph**.

## **Dataset**
The dataset used for testing is from **Stanford Large Network Dataset Collection**:
- **Google Web Graph Dataset:** [Download Here](https://snap.stanford.edu/data/web-Google.html)
- **Twitter Ego Network Dataset:** [Download Here](https://snap.stanford.edu/data/ego-Twitter.html)

## **Implementation Details**
- The program reads a directed graph from a dataset.
- Constructs an adjacency list representation of the graph.
- Uses **DFS traversal** to detect **Strongly Connected Components (SCCs)**.
- Computes and outputs:
  - **Total number of SCCs**
  - **Size of the largest SCC**

## **Key Functions**
1. **Depth First Search (DFS)**: Recursively explores nodes and marks visited ones.
2. **SCC Computation**: Uses forward and reverse DFS to identify SCCs.

