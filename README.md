# 🧠 Memory-Optimized Telemetry Logger (Robot Black Box)

## 📌 Project Overview

This project implements a **Deterministic Telemetry Logger** for an **Industrial Robot / AMR (Autonomous Mobile Robot)**.  
It functions as a robotic **“black box”**, recording and retaining critical runtime data such as **Speed, Temperature, and System Status**.

The design emphasizes **memory efficiency**, **deterministic behavior**, and **safe data recovery**, making it suitable for **embedded and safety-critical systems**.

---

## 🚀 Key Technical Features

### 🔁 Circular Buffer (Memory-Safe Design)

- Fixed-size array (no dynamic allocation)
- Modulo arithmetic for index wrapping
- Prevents memory leaks and heap fragmentation
- Deterministic and real-time safe

---

### 🧩 Custom Data Structures

Uses `struct` to group telemetry fields:

- Log ID
- Speed
- Temperature
- System Status

Improves **code clarity** and **data integrity**.

---

### 🛡️ Fail-Safe Crash Dump

- Dedicated `crash_dump()` function
- Dumps last valid logs on failure
- Enables post-mortem analysis

---

## 📊 Logic Flow

- User enters **6 telemetry records**
- Buffer size (`MAX_LOGS`) = **5**
- 6th record overwrites the oldest record
- `crash_dump()` prints the most recent **5 logs**

---

## 📂 Data Structure Design

```c
typedef struct {
    int id;
    float speed;
    float temperature;
    int status;
} TelemetryLog;
Each struct represents one snapshot of robot state

Stored inside a circular buffer

##🔁 Circular Buffer Logic (Core Concept)
index = (index + 1) % MAX_LOGS;


Automatically wraps when buffer is full

Ensures continuous logging without memory growth

##🛡️ Crash Dump Mechanism
void crash_dump() {
    for (int i = 0; i < MAX_LOGS; i++) {
        printf("Log %d: Speed=%.2f Temp=%.2f Status=%d\n",
               logs[i].id,
               logs[i].speed,
               logs[i].temperature,
               logs[i].status);
    }
}


✔ Dumps only valid recent data
✔ Simulates real-world robot black box recovery

##🧪 Sample Input
Enter Speed: 10
Enter Temperature: 35
Enter Status: 1
(repeated for 6 entries)

##🖥️ Sample Output
--- CRASH DUMP ---
Log ID: 2 | Speed: 12.5 | Temp: 36.0 | Status: 1
Log ID: 3 | Speed: 13.0 | Temp: 37.2 | Status: 1
Log ID: 4 | Speed: 11.8 | Temp: 38.1 | Status: 0
Log ID: 5 | Speed: 14.0 | Temp: 39.0 | Status: 1
Log ID: 6 | Speed: 15.2 | Temp: 40.3 | Status: 1

##📌 Note

Log ID 1 is overwritten due to circular buffer behavior.

##🛠️ Build and Run Instructions
##✅ Requirements

GCC Compiler

##🔧 Compile
gcc main.c -o logger

##▶️ Execute
./logger

##📌 Use Cases

Industrial Robots (AMR / AGV)

Embedded Systems Telemetry

Automotive Event Logging

Safety-Critical Diagnostics

##📚 Concepts Demonstrated

Circular Buffer Implementation

Embedded-Friendly Memory Management

Struct-Based Data Modeling

Fail-Safe Crash Recovery

Deterministic System Design

##🧑‍💻 Author

Ankit
Systems Programming | Embedded C | Robotics-Oriented Design
