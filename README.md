# C++ Task Manager

This C++ program simulates a basic task manager. It retrieves a list of currently running processes on a Windows system using the `tasklist` command, parses the output, and allows the user to display and sort this information.

## How it Works

1.  The program executes the `tasklist` command and redirects its output to a temporary file (`data.txt`).
2.  It then reads `data.txt`, parsing each line to extract process information: Image Name, PID (Process ID), Session Name, Session Number, and Memory Usage.
3.  This data is stored in a list of `Process` objects.
4.  The user is then presented with options to display the processes sorted by name, PID, or memory usage.

## Features

- **Process Listing:** Fetches and displays currently running processes.
- **Data Extraction:** Parses information such as PID, session details, and memory usage for each process.
- **Sorting Options:**
  - Sort processes alphabetically by Image Name.
  - Sort processes numerically by PID.
  - Sort processes by Memory Usage (descending).
- **Formatted Output:** Displays the process list in a clean, tabular format.

## Prerequisites

- **Operating System:** Windows (due to the use of `tasklist` command).
- **Compiler:** A C++ compiler that supports C++11 or later (e.g., g++ via MinGW on Windows).

## How to Compile and Run

### Compilation

The program uses the `<bits/stdc++.h>` header, which is a non-standard GCC extension. Ensure your compiler supports this or replace it with individual standard headers.

**Using GCC (e.g., via MinGW on Windows):**

```bash
g++ A2_s7-8_20230287_sheetpb05.cpp -o task_manager -std=c++11
```

**Using Standard Headers (if `<bits/stdc++.h>` is not available):**

You would need to replace `#include<bits/stdc++.h>` with standard headers like:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip> // For setw
#include <cstdlib> // For system()
#include <cctype>  // For toupper()
// Potentially others depending on specific standard library features used indirectly.
```

Then compile as above.

### Running the Program

Once compiled, you can run the executable from the command line:

```bash
.\task_manager.exe
```

Or simply:

```bash
task_manager
```

The program will then display the menu for sorting options.

**Note:** The program requires permissions to execute `tasklist` and to create `data.txt` in the current directory.

## Program Workflow

1.  The program starts and automatically loads the process list.
2.  **Menu Options:**
    - **A) Sorted by Name:** Displays processes sorted alphabetically.
    - **B) Sorted by PID:** Displays processes sorted by their Process ID.
    - **C) Sorted by Memory Usage:** Displays processes sorted by memory consumption (highest first).
    - **D) Exit:** Terminates the program.
3.  The program loops, allowing the user to choose different sorting options until they exit.

## Author

Fahd Deya El-din Salah

## Date

25 Nov. 2024
