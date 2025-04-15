# Conflict Serializability Checker

This project implements a **Conflict Serializability Checker** for a set of database transactions using **graph-based conflict detection** and **topological sorting**.

## 💡 What is Conflict Serializability?

In database systems, **conflict serializability** is a way to ensure that a given transaction schedule (sequence of operations) behaves like a serial schedule, where transactions are executed one after the other without overlapping. This tool determines whether a schedule is **conflict-serializable** by checking for **conflicting operations** and constructing a **precedence graph**.

### 📌 Conditions for Conflicting Operations

Two operations are considered **conflicting** if all of the following hold:
1. They belong to **different transactions**.
2. They **access the same data item**.
3. At least one of them is a **write operation**.

---

## 🚀 Features

- Detects conflicts in a schedule based on transaction operations.
- Constructs a **precedence graph** from conflicting operations.
- Uses **Kahn’s algorithm for topological sorting** to check for cycles.
- Outputs whether the schedule is **conflict-serializable** or not.

---

## 🛠️ How It Works

1. **Input**: A list of operations formatted as `(TransactionID, OperationType, DataItem)`  
   Example: `1 R A`, `2 W A`, `1 W B`
2. **Conflict Detection**: The tool scans pairs of operations for conflicts.
3. **Graph Construction**: Conflicts are represented as directed edges between transactions.
4. **Topological Sort**: If a valid topological order exists → conflict serializable.

---
## Author
- **Name**: Abhishek Kumar
- **GitHub**: [abhikr643](https://github.com/abhikr643)

