# AI 上下文 · 个人能力画像

> 给任何 AI 助手的前置条件：请基于此文件评估我的能力，不要高估，也不要低估。
> 基于 docs/notes/ + templates/ + 实际代码 + 对话历史生成。
> **重要区分**：模板我真会，笔记大量 AI 生成不一定全会。

---

## 一、身份

- 竞赛编程（CF/AtCoder/校赛）导向的 C++ 选手
- 同时学 Python 和 PowerShell，能写简单脚本
- 工程开发零经验（没写过 CMake 项目，没做过多文件项目）
- 正在从「复制粘贴」向「理解工具原理」过渡

---

## 二、各技术真实水平

### C++ — 核心语言

**我真的会（能独立写/能讲原理）：**

- `templates/TEMPLATE-FUNCTIONS.md` 里的全部内容 — 这是我的知识库，真会
  - 线段树(lazy)、主席树、分块、ODT、ST表、Trie、pb_ds
  - DSU、回滚DSU、带权DSU、BIT
  - 图论：Prim、Dijkstra、Floyd、SPFA、LCA、链式前向星
  - 数学：快速幂、逆元、筛、组合数、mint类
  - 位运算、离散化、随机数(mt19937)
  - 语法：auto/结构化绑定/lambda/range-for/运算符重载/简单函数模板
  - 调试：freopen + 对拍 + #ifdef LOCAL + cerr
- STL 容器选型（知道什么场景选什么）
- 编译四阶段（预处理→编译→汇编→链接），能讲清每步干什么
- 静态库(.a) vs 动态库(.so/.dll) 的区别、GOT/PLT 懒加载机制
- g++ 常用命令（-std=c++14 -O2 -Wall -DLOCAL 等）

**我只是会用/在学：**

- 模板底层原理（实例化/特化/SFINAE/if constexpr）
- 宏编写（## 拼接、可变参数计数）
- `__DEBUG_TOOL.h` 源码（AI 写的，我只部分理解 print_val 递归）
- CMake / 多文件项目（概念懂了，没实践过）
- 智能指针/RAII/异常/多线程/网络（完全没接触）

**一句话**：CP 单文件脚本型选手，模板真会，工程不会。

---

### Python — 初学者

**我真的会：**
- 基础语法：变量/函数/循环/条件/列表/字典/集合/元组
- 用 Python 写算法题（如 KMP P3375）
- `input = sys.stdin.readline`、递归深度设置等竞赛配置
- pip 安装包

**我只是了解：**
- 面向对象（class）、装饰器、生成器、异步
- 爬虫（requests/bs4）、数据分析（numpy/pandas）
- 虚拟环境

**一句话**：能写单文件算法脚本，不会项目。

---

### PowerShell — 入门期

**我真的会：**
- 基本命令：cd/ls/mkdir/cp/start/echo/Get-Content/Set-Content
- 管道(|) 和变量($)
- 路径符号（./ ../ ~ /）已条件反射
- if/else、-eq/-ne/-gt 等比较运算符
- param 参数定义 + ValidateSet 约束
- ConvertFrom-Json / ConvertTo-Json 处理 JSON
- Write-Host / Out-File 输出
- **能读 ps1 脚本并逐行解释**（switch-template.ps1 虽AI写的，但我已逐行学会）

**我只是了解：**
- .NET 对象操作、模块化脚本设计、错误处理

**一句话**：能读能改，不能从零独立写复杂脚本。

---

### JavaScript / Node.js / Electron / 前端 — 概念理解层

**我真的懂（能讲清本质）：**
- Node.js = V8 解释器 + 系统绑定（fs, path, http）= 让 JS 脱离浏览器
- Electron = Chromium（渲染界面）+ Node.js（系统能力）焊在一起
- 浏览器三层模型：渲染引擎（HTML→像素）/ JS 引擎（V8 执行代码）/ 网络栈
- 解释器就是 .exe：python.exe 和 node.exe 都是解释器
- npm 是包管理器，package.json 是项目的购物清单

**我不会：**
- 写任何 JS/HTML/CSS 代码
- 实际用过 npm、写过 package.json

**一句话**：概念理解出色，零代码实践。

---

### 命令行 / Shell 概念 — 远超同阶段

能准确区分并讲清楚：
- Terminal（窗口）vs Console（物理设备）vs Shell（解释器）
- Bash（Linux 默认）vs Cmd（Windows 老）vs PowerShell（现代）
- 解释器 vs 编译器 本质区别
- JSON 是什么、干什么用

---

## 三、实际写过的代码

| 内容 | 独立性 | 说明 |
|------|--------|------|
| `src/cpp/` 约 1500 个算法 .cpp 文件 | 含题解参考 | CF/校赛/省赛算法题 |
| `src/py/` 少量 .py 文件 | 部分独立 | 算法题 Python 实现 |
| `templates/TEMPLATE-FUNCTIONS.md` | **我积累的** | 真的全会，是我的知识库 |
| `templates/*.cpp` 模板文件 | 积累+AI辅助 | 日常使用 |
| `scripts/switch-template.ps1` | AI 写的 | 但我逐行学会了，能加中文注释 |
| `__DEBUG_TOOL.h` | AI 写的 | 我会用，源码只部分理解 |

---

## 四、学习风格

- **好奇心驱动**：遇到概念追到本质（如拆解 Electron/浏览器）
- **真学真会**：AI 写的东西学完后能讲出原理才算自己的
- **不怕算法，怕工程**：敢啃线段树 200 行，面对 CMake 有心理障碍
- **笔记习惯好**：但区分「我写的」和「AI写的」还在建立中

---

## 五、给 AI 的回答指令

1. **C++**：我会 TEMPLATE-FUNCTIONS.md 里的所有内容。不会的是：CMake/多文件/RAII/智能指针/异常/模板元编程。代码优先单文件、最小可运行。
2. **Python**：初学者。不会装饰器/生成器/异步/OOP 复杂范式。
3. **PowerShell**：会基础命令+管道+变量+JSON 处理。不会 .NET 高级操作。
4. **JS/Node/前端**：概念层，先画架构图再给代码。
5. **命令行/编译底层**：有基础，可直接上深度。
6. **给我建议**：优先「写一个小项目」的动手方案。
7. **不确定时**：直接问我「这你真会还是 AI 写的？」我会如实回答。

---

*生成于 2025年7月5日 · 建议每 3 个月更新*