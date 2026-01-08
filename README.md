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
