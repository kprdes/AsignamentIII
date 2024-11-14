## Members

- Kevin Pérez Román

### Disk Scheduling Program Documentation

This C++ program simulates the **SCAN** and **CSCAN** disk scheduling algorithms for managing requests on a disk drive. The goal is to minimize the seek time by ordering the requests in a way that optimizes the head movements.

### Program Overview

1. **SCAN Algorithm**: The SCAN algorithm, also known as the "elevator algorithm," moves the disk head in a specific direction until it reaches the last request in that direction. After reaching the end, it reverses direction and processes requests in the opposite direction.
   
2. **CSCAN Algorithm**: CSCAN, or "Circular SCAN," moves the disk head in one direction, processes all requests along that path, and then jumps back to the beginning of the disk without processing any requests in the reverse direction. This jump to the beginning ensures a more uniform wait time for requests across all disk tracks.

### Code Structure

- **Functions**:
  - `scan()`: Implements the SCAN algorithm.
  - `cscan()`: Implements the CSCAN algorithm.

- **File Input**:
  - The program reads requests from a text file (`solicitudes.txt`), where each line represents a track request.

### Code Implementation

#### Header Files

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
```

- `#include <iostream>`: Used for input/output operations.
- `#include <fstream>`: Used for file handling to read requests from a file.
- `#include <vector>`: Used to store track requests.
- `#include <algorithm>`: Provides sorting functions.
- `#include <cmath>`: Allows for mathematical operations such as `abs()` for calculating absolute values.

#### SCAN Algorithm Implementation

The SCAN algorithm processes requests by first dividing them into two groups:
1. **Left**: Requests that are to the left of the initial head position.
2. **Right**: Requests that are to the right of the initial head position.

The function then:
1. **Sorts the requests** in both directions.
2. **Processes requests in one direction** until reaching the end.
3. **Reverses direction** and processes requests in the other direction.


#### CSCAN Algorithm Implementation

The CSCAN algorithm also divides requests into left and right groups. However, unlike SCAN, when the head reaches the last request in the current direction:
1. **The head jumps back to the start** of the disk without servicing requests on the return path.
2. **The head continues from the beginning**, servicing any requests along the way.

### Main Function

The main function:
1. **Reads requests from a text file**.
2. **Initializes parameters** for head position and disk size.
3. **Runs both SCAN and CSCAN algorithms** and outputs the sequence and seek count.

### Explanation of the SCAN and CSCAN Algorithms

#### SCAN (Elevator) Algorithm:
1. **Description**: The SCAN algorithm moves the disk head in a fixed direction until it reaches the end or the last request in that direction. It then reverses and serves requests in the opposite direction.
2. **Usage**: Suitable for environments where requests are spread across the disk, but where some bias toward the center is acceptable.
3. **Advantages**: Efficient use of head movements and reduced seek time for most requests.
4. **Disadvantages**: Requests at the extremes of the disk may experience longer wait times.

#### CSCAN (Circular SCAN) Algorithm:
1. **Description**: Similar to SCAN but with one important difference. When the disk head reaches the end, it jumps directly back to the beginning and processes requests only in one direction. This improves fairness across all requests.
2. **Usage**: Recommended for systems where a uniform response time is essential for requests regardless of their location on the disk.
3. **Advantages**: More consistent wait times, especially for requests at the edges.
4. **Disadvantages**: Slightly more head movement compared to SCAN, as it involves a jump back to the beginning.

### Example Workflow
1. **User Input**: The user inputs the initial head position and disk size.
2. **Request File**: The program reads requests from `solicitudes.txt`.
3. **Execution**:
   - The `scan()` function executes the SCAN algorithm, printing the order of serviced tracks and total seek count.
   - The `cscan()` function then runs the CSCAN algorithm, displaying its own service order and seek count.
4. **Output**: For both algorithms, the program outputs the seek sequence and total distance traveled by the head.

### Notes
- **File Requirements**: The program expects a file named `solicitudes.txt` with one request per line.
- **Efficiency**: Both algorithms are designed to minimize seek time, but their usage depends on specific requirements such as fairness (CSCAN) or minimal head movement (SCAN).

### This document was created with the help of AI to improve the writing, translation, increase the descriptions of the functioning of the algorithms, the workflow and speed up the creation of the document.
