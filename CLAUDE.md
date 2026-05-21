# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

```bash
# Compile and run
gcc 源.cpp -o 源 && ./源

# Or with g++ (file uses .cpp extension but is C-style code)
g++ 源.cpp -o 源 && ./源
```

## Code Structure

Single-file C implementation of a **singly linked list** (单链表) for learning purposes.

- **`源.cpp`** — Contains everything: node struct (`SLTNode`), list operations, and a `main()` test
- No build system, no tests framework, no headers — single translation unit

### Operations implemented:
| Function | Description |
|----------|-------------|
| `createList()` | Creates a fixed 4-node list (12→23→34→45) |
| `SLTPrint()` | Print all nodes |
| `SLTPushFront()` | Insert at head |
| `SLTHeadDelete()` | Delete head node |
| `SLTPushBack()` | Append at tail |
| `SLTPopBack()` / `SLTPopBack2()` | Delete tail node (two approaches) |
| `SLTFind()` | Find node by value |
| `SLTInsert()` | Insert at positional index |
| `SLTErase()` | Delete node by key value |
| `SLTDelete()` | Destroy entire list |

### Notes:
- Compiled with MinGW (`gcc`/`g++` at `/d/mingw64/bin/`)
- Uses `_CRT_SECURE_NO_WARNINGS` for MSVC compatibility
- No memory leak detection or valgrind configured
