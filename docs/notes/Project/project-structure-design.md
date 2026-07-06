[你真的会正确的分层/组织你的代码结构吗](https://www.bilibili.com/video/BV1Jk4y1q7Zy/)
[大型企业软件开发是什么样子的？ - Web Dev Cody](https://www.bilibili.com/video/BV1xC411n7mL/)
## 常见的 c++ 项目结构
```
MyProject/
├── CMakeLists.txt          // CMake 的“说明书”，放在根目录
├── src/                    // 源代码（.cpp）
│   ├── main.cpp
│   └── ...
├── include/                // 头文件（.h, .hpp）
│   └── MyClass.h
├── assets/                 // 图片、字体、声音等资源
├── lib/                    // 第三方库（有时叫 external/ 或 third_party/）
├── build/                  // 编译输出（别手动改，由 CMake 生成）
├── tests/                  // 测试代码（有时叫 test/）
└── README.md               // 项目说明
```

好，我把一张**手绘式的项目结构全景图**送给你，从根目录一直到底层，每个文件夹里放什么、干什么，全部标清楚。

---

## 🗺️ C++ 项目目录结构全景图（以 CMake 为例）

```
MyProject/                          <-- 项目根目录
│
├── CMakeLists.txt                  <-- [说明书] CMake 的总指挥文件
│
├── src/                            <-- [我的源码] 你写的 .cpp 实现文件
│   ├── main.cpp                    <-- 程序入口，包含 main() 函数
│   ├── math.cpp                    <-- 某个模块的实现
│   ├── network/
│   │   ├── client.cpp
│   │   └── server.cpp
│   └── ...
│
├── include/                        <-- [我的头文件] 模块的声明 (.h/.hpp)
│   ├── math.h
│   ├── network/
│   │   ├── client.h
│   │   └── server.h
│   └── ...
│
├── lib/                            <-- [第三方预编译库] 已编译好的库文件 (可选)
│   ├── SDL2/
│   │   ├── lib/                    <-- 放 .a, .lib, .so, .dll
│   │   └── include/               <-- 第三方库的头文件
│   └── ...
│
├── external/  (或 third_party/)    <-- [第三方源码] 那些直接带源码的小库
│   ├── imgui/
│   │   ├── imgui.cpp
│   │   └── imgui.h
│   └── ...
│
├── assets/                         <-- [静态资源] 图片、字体、声音、模型等
│   ├── textures/
│   ├── fonts/
│   ├── sounds/
│   └── ...
│
├── tests/                          <-- [测试代码] 单元测试、集成测试
│   ├── test_math.cpp
│   ├── test_network.cpp
│   └── CMakeLists.txt             <-- 测试也需要自己的 CMakeLists
│
├── docs/                           <-- [文档] API 文档、设计文档、图片
│   ├── design.md
│   └── api_reference/
│
├── config/                         <-- [配置文件] 程序运行需要的配置
│   ├── settings.json
│   └── logging.conf
│
├── scripts/                        <-- [辅助脚本] 构建、部署、格式化等
│   ├── build.sh                    <-- 或 build.ps1
│   ├── setup_env.sh
│   └── ...
│
├── build/                          <-- [构建工厂] 所有编译生成的临时文件
│   ├── CMakeCache.txt              <-- CMake 的缓存
│   ├── Makefile                    <-- 生成的 Makefile (或 .sln 等)
│   ├── main.cpp.o                  <-- 中间目标文件
│   ├── app(.exe)                   <-- 最终可执行文件 (就在这里!)
│   └── ...
│
└── README.md                       <-- [脸面] 项目介绍、使用方法、依赖说明
```

---

## 📌 目录角色速查表

| 目录 | 里面装什么 | 谁产生的 | 备注 |
|------|-----------|---------|------|
| `src/` | 你的 `.cpp` 源代码 | 你 | 按模块分子文件夹 |
| `include/` | 你的 `.h`/`.hpp` 头文件 | 你 | 也可以放第三方头文件 |
| `lib/` | 第三方预编译库(.a/.lib/.so/.dll) | 别人给你的 | 一般会自带自己的头文件 |
| `external/` | 第三方源代码 | 别人给你的（源码形态） | 也被称为 `third_party/` |
| `assets/` | 图片、字体、声音、模型 | 你/设计师 | 程序运行时读取 |
| `tests/` | 测试代码 (.cpp) | 你 | 通常也有 `CMakeLists.txt` |
| `docs/` | 文档 .md/.pdf 等 | 你 | 项目越大这个越重要 |
| `config/` | 运行时配置文件 | 你 | 如 json、xml、ini |
| `scripts/` | 自动化脚本 (.sh/.ps1) | 你 | 环境配置、一键部署 |
| `build/` | 所有编译中间产物 + exe | CMake + 编译器 | 可删除，不进版本管理 |
| `CMakeLists.txt` | CMake 总指挥 | 你 | 根目录必须有一个 |
| `README.md` | 项目说明书 | 你 | 用 Markdown 写 |

---

## 🧠 补充几个你可能会问的点

### 1. `include/` 和 `lib/` 里的第三方套件怎么区分？
- 大的第三方库（如 SDL2）通常单独占一个文件夹，里面再分 `include` 和 `lib`。
- 有的项目为了整洁，会在项目根目录建一个 `deps/` 或 `packages/`，然后把所有第三方库的“头文件 + 库文件”放进去，但这需要配合 CMake 的 `find_package` 或自己去配路径。

### 2. `external/` 和 `lib/` 的区别
- `lib/` 存放**二进制形式的库**（已编译）。
- `external/` 存放**源码形式的第三方库**（你会把它们的 `.cpp` 和 `.h` 一起编译进你的项目）。很多一两个文件的库就直接放这里，省心。

### 3. 为什么 `build/` 绝对不能手改？
因为它完全由 CMake 生成，你每次 `cmake ...` 都可能覆盖它。你的修改会在下次构建时消失。遇到问题把整个 `build/` 删掉，重新 `cmake` 是最干净的修复方式。

### 4. 最终 exe 在哪里？
就在 `build/` 的根目录下，或者你可以设置 `CMAKE_RUNTIME_OUTPUT_DIRECTORY` 把它送到 `build/bin/` 下。

---
