# Design and Analysis of Algorithms (DAA) — Lab Programs

[![Language: C](https://img.shields.io/badge/Language-C99%20%2F%20C11-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC%20%7C%20Clang%20%7C%20MSVC-green.svg)](https://gcc.gnu.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![DAA Coursework](https://img.shields.io/badge/Coursework-DAA%20%26%20CodeTantra-orange.svg)](#)

A comprehensive, production-grade repository of fundamental **Design and Analysis of Algorithms (DAA)** laboratory experiments. Every experiment features fully functional, thoroughly commented, warning-free **C** source code with input validation, execution statistics, and dedicated standalone documentation.

---

## 📑 Table of Contents

- [Overview & Objectives](#-overview--objectives)
- [List of Experiments](#-list-of-experiments)
- [Master Complexity Reference Table](#-master-complexity-reference-table)
- [Repository Directory Structure](#-repository-directory-structure)
- [Compilation & Execution Guide](#-compilation--execution-guide)
- [Continuous Assessment 3 (CA3) Deliverables](#-continuous-assessment-3-ca3-deliverables)
- [System Requirements & Toolchain](#-system-requirements--toolchain)
- [License](#-license)

---

## 🎯 Overview & Objectives

The primary objective of this laboratory repository is to design, implement, test, and analyze the computational complexities of core algorithms across four major algorithmic paradigms:
1. **Divide and Conquer:** Breaking a problem into independent sub-problems, solving each recursively, and combining their results.
2. **Greedy Method:** Making locally optimal choices at each stage in the hope of reaching a global optimum.
3. **Dynamic Programming (DP):** Breaking problems into overlapping subproblems, solving each once, and storing solutions in a table to prevent redundant work.
4. **Backtracking:** Incrementally building candidates for solutions and abandoning (pruning) a candidate as soon as it is determined that it cannot possibly lead to a valid solution.

---

## 📚 List of Experiments

The experiments are systematically organized and numbered from **01** to **13**:

| # | Experiment Name | Algorithmic Paradigm | Source Code | Documentation |
| :-: | :--- | :--- | :---: | :---: |
| **01** | **Quick Sort** | Divide and Conquer | [quick_sort.c](./01-Quick-Sort/quick_sort.c) | [README.md](./01-Quick-Sort/README.md) |
| **02** | **Merge Sort** | Divide and Conquer | [merge_sort.c](./02-Merge-Sort/merge_sort.c) | [README.md](./02-Merge-Sort/README.md) |
| **03** | **Prim's MST Algorithm** | Greedy Approach | [prims_mst.c](./03-Prims-MST/prims_mst.c) | [README.md](./03-Prims-MST/README.md) |
| **04** | **Kruskal's MST Algorithm** | Greedy Approach (Disjoint Sets) | [kruskals_mst.c](./04-Kruskals-MST/kruskals_mst.c) | [README.md](./04-Kruskals-MST/README.md) |
| **05** | **Sum of Subsets Problem** | Backtracking | [sum_of_subsets.c](./05-Sum-of-Subsets/sum_of_subsets.c) | [README.md](./05-Sum-of-Subsets/README.md) |
| **06** | **Dijkstra's Algorithm** | Greedy Approach | [dijkstras_algorithm.c](./06-Dijkstras-Algorithm/dijkstras_algorithm.c) | [README.md](./06-Dijkstras-Algorithm/README.md) |
| **07** | **Bellman-Ford Algorithm** | Dynamic Programming | [bellman_ford.c](./07-Bellman-Ford/bellman_ford.c) | [README.md](./07-Bellman-Ford/README.md) |
| **08** | **Strassen's Matrix Multiplication** | Divide and Conquer | [matrix_multiplication.c](./08-Matrix-Multiplication/matrix_multiplication.c) | [README.md](./08-Matrix-Multiplication/README.md) |
| **09** | **Breadth-First Search (BFS)** | Graph Traversal (Queue ADT) | [bfs.c](./09-BFS/bfs.c) | [README.md](./09-BFS/README.md) |
| **10** | **Depth-First Search (DFS)** | Graph Traversal (Recursion / Stack) | [dfs.c](./10-DFS/dfs.c) | [README.md](./10-DFS/README.md) |
| **11** | **0/1 Knapsack Problem** | Dynamic Programming | [knapsack.c](./11-Knapsack/knapsack.c) | [README.md](./11-Knapsack/README.md) |
| **12** | **Longest Common Subsequence (LCS)** | Dynamic Programming | [longest_common_subsequence.c](./12-Longest-Common-Subsequence/longest_common_subsequence.c) | [README.md](./12-Longest-Common-Subsequence/README.md) |
| **13** | **Travelling Salesman Problem (TSP)** | DP with Bitmasking (Held-Karp) | [travelling_salesman.c](./13-Travelling-Salesman/travelling_salesman.c) | [README.md](./13-Travelling-Salesman/README.md) |

---

## ⚡ Master Complexity Reference Table

| # | Algorithm | Best Time | Average Time | Worst Time | Space Complexity | Paradigm |
| :-: | :--- | :---: | :---: | :---: | :---: | :--- |
| 01 | **Quick Sort** | $\Omega(n \log n)$ | $\Theta(n \log n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(\log n)$ aux | Divide & Conquer |
| 02 | **Merge Sort** | $\Omega(n \log n)$ | $\Theta(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ aux | Divide & Conquer |
| 03 | **Prim's MST** | $\Omega(V^2)$ | $\Theta(V^2)$ | $\mathcal{O}(V^2)$ | $\mathcal{O}(V)$ | Greedy |
| 04 | **Kruskal's MST** | $\Omega(E \log E)$ | $\Theta(E \log E)$ | $\mathcal{O}(E \log E)$ | $\mathcal{O}(V + E)$ | Greedy |
| 05 | **Sum of Subsets** | $\Omega(1)$ | $\mathcal{O}(2^n)$ (pruned) | $\mathcal{O}(2^n)$ | $\mathcal{O}(n)$ | Backtracking |
| 06 | **Dijkstra's SSSP** | $\Omega(V^2)$ | $\Theta(V^2)$ | $\mathcal{O}(V^2)$ | $\mathcal{O}(V)$ | Greedy |
| 07 | **Bellman-Ford SSSP** | $\Omega(E)$ | $\Theta(V \cdot E)$ | $\mathcal{O}(V \cdot E)$ | $\mathcal{O}(V)$ | Dynamic Programming |
| 08 | **Strassen's Matrix Mult** | $\Omega(n^{2.81})$ | $\Theta(n^{2.81})$ | $\mathcal{O}(n^{\log_2 7}) \approx \mathcal{O}(n^{2.807})$ | $\mathcal{O}(n^2)$ | Divide & Conquer |
| 09 | **Breadth-First Search** | $\Omega(V + E)$ | $\Theta(V^2)$ | $\mathcal{O}(V^2)$ (Matrix) | $\mathcal{O}(V)$ | Graph Traversal |
| 10 | **Depth-First Search** | $\Omega(V + E)$ | $\Theta(V^2)$ | $\mathcal{O}(V^2)$ (Matrix) | $\mathcal{O}(V)$ | Graph Traversal |
| 11 | **0/1 Knapsack** | $\Omega(n \cdot W)$ | $\Theta(n \cdot W)$ | $\mathcal{O}(n \cdot W)$ | $\mathcal{O}(n \cdot W)$ | Dynamic Programming |
| 12 | **Longest Common Subsequence** | $\Omega(m \cdot n)$ | $\Theta(m \cdot n)$ | $\mathcal{O}(m \cdot n)$ | $\mathcal{O}(m \cdot n)$ | Dynamic Programming |
| 13 | **Travelling Salesman (TSP)** | $\Omega(n^2 \cdot 2^n)$ | $\Theta(n^2 \cdot 2^n)$ | $\mathcal{O}(n^2 \cdot 2^n)$ | $\mathcal{O}(n \cdot 2^n)$ | DP + Bitmasking |

---

## 📁 Repository Directory Structure

```text
DAA-Lab-Programs/
│
├── 01-Quick-Sort/
│   ├── quick_sort.c
│   └── README.md
├── 02-Merge-Sort/
│   ├── merge_sort.c
│   └── README.md
├── 03-Prims-MST/
│   ├── prims_mst.c
│   └── README.md
├── 04-Kruskals-MST/
│   ├── kruskals_mst.c
│   └── README.md
├── 05-Sum-of-Subsets/
│   ├── sum_of_subsets.c
│   └── README.md
├── 06-Dijkstras-Algorithm/
│   ├── dijkstras_algorithm.c
│   └── README.md
├── 07-Bellman-Ford/
│   ├── bellman_ford.c
│   └── README.md
├── 08-Matrix-Multiplication/
│   ├── matrix_multiplication.c
│   └── README.md
├── 09-BFS/
│   ├── bfs.c
│   └── README.md
├── 10-DFS/
│   ├── dfs.c
│   └── README.md
├── 11-Knapsack/
│   ├── knapsack.c
│   └── README.md
├── 12-Longest-Common-Subsequence/
│   ├── longest_common_subsequence.c
│   └── README.md
├── 13-Travelling-Salesman/
│   ├── travelling_salesman.c
│   └── README.md
│
├── CA3/
│   ├── PPT/
│   │   └── README.md
│   ├── Video/
│   │   └── README.md
│   └── README.md
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## 🛠️ Compilation & Execution Guide

All programs are implemented adhering to the **ANSI C / C99** standard and compile cleanly across Windows, Linux, and macOS without external dependencies.

### 1. Prerequisites
- **Compiler:** `gcc` (MinGW-w64 on Windows, GNU Compiler Collection on Linux/macOS) or `clang`.
- Verify installation by running:
  ```bash
  gcc --version
  ```

### 2. Compiling and Running an Individual Experiment
To run any specific experiment (for example, Experiment 01: Quick Sort):

```bash
# Step 1: Navigate to the experiment directory
cd 01-Quick-Sort

# Step 2: Compile the C source code
gcc -Wall -Wextra -std=c99 quick_sort.c -o quick_sort

# Step 3: Run the executable
# On Windows (PowerShell / Command Prompt):
.\quick_sort.exe

# On Linux / macOS:
./quick_sort
```

### 3. One-Liner Quick Test Commands (Windows PowerShell)
```powershell
# Example: Compile & run 01-Quick-Sort
gcc -Wall -Wextra -std=c99 "01-Quick-Sort\quick_sort.c" -o "01-Quick-Sort\quick_sort.exe"; & ".\01-Quick-Sort\quick_sort.exe"

# Example: Compile & run 11-Knapsack
gcc -Wall -Wextra -std=c99 "11-Knapsack\knapsack.c" -o "11-Knapsack\knapsack.exe"; & ".\11-Knapsack\knapsack.exe"
```

---

## 🎓 Continuous Assessment 3 (CA3) Deliverables

The [📁 CA3/](./CA3/) directory contains resources and guidelines for internal academic evaluation:

- **[📁 CA3/PPT/](./CA3/PPT/) — Presentation Slide Decks:**
  - Dedicated folder for uploading presentation slides (`.pptx`, `.pdf`).
  - Read [CA3/PPT/README.md](./CA3/PPT/README.md) for the recommended slide deck structure and assessment rubrics.
- **[📁 CA3/Video/](./CA3/Video/) — Video Demonstrations:**
  - Dedicated folder for video walkthroughs, code explanations, and viva recordings (`.mp4`, `.mkv`).
  - Read [CA3/Video/README.md](./CA3/Video/README.md) for recording guidelines, resolution specifications, and upload instructions.

---

## 💻 System Requirements & Toolchain

- **Operating System:** Windows 10/11, Ubuntu 20.04+, macOS 12+
- **Recommended IDE / Editor:** [Visual Studio Code](https://code.visualstudio.com/) with the *C/C++* extension by Microsoft.
- **Terminal Shell:** PowerShell 5.1+ / 7+, Bash, or Zsh.

---

## 📄 License

This repository is distributed under the [MIT License](./LICENSE). You are free to use, modify, and distribute this codebase for academic, educational, and personal learning purposes.
