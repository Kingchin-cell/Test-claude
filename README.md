# 单链表实现 (Singly Linked List)

一个用 C 语言实现的单链表学习项目，包含链表常见操作的完整实现。

## 功能列表

| 操作 | 说明 |
|------|------|
| `createList()` | 创建固定链表 `12 -> 23 -> 34 -> 45` |
| `SLTPrint()` | 遍历并打印所有节点 |
| `SLTPushFront()` | 头部插入新节点 |
| `SLTHeadDelete()` | 删除头节点 |
| `SLTPushBack()` | 尾部追加新节点 |
| `SLTPopBack()` / `SLTPopBack2()` | 尾部删除（两种实现方式） |
| `SLTFind()` | 按值查找节点 |
| `SLTInsert()` | 按位置索引插入节点 |
| `SLTErase()` | 按关键字删除节点 |
| `SLTDelete()` | 销毁整个链表，释放所有内存 |

## 编译与运行

### 环境要求
- GCC / G++ (MinGW)
- C99 或更高标准

### 编译运行
```bash
gcc 源.cpp -o 源 && ./源
# 或
g++ 源.cpp -o 源 && ./源
```

## 项目结构

```
.
├── 源.cpp      # 单链表完整实现（含测试 main 函数）
├── README.md   # 本文件
└── CLAUDE.md   # Claude Code 配置文件
```

## 学习要点

- 链表的动态内存管理（`malloc` / `free`）
- 头指针与二级指针的使用场景
- 头插、头删、尾插、尾删的实现差异
- 链表的遍历、查找、按位插入与按值删除
