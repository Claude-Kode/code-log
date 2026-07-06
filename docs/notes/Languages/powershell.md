[【技术杂谈】shell和terminal](https://www.bilibili.com/video/BV16A411675V)
问题: 
shell 
bash
terminal
console 
cmd
powershell 
感觉都是一个东西啊

哦

shell 是一个概念, 就是他是一种解释器
这种解释器专门用来 翻译
人们通过 terminal 发送的, 想和计算机交互的语言
并且这个解释器还有交互(返回信息) 的功能
linux 的 shell 叫 bash
windows 的 shell 先是 cmd, 再是 powershell
console 是物理意义上的 terminal
terminal 就是那个交互的黑色窗口

Shell 是一种交互式命令解释器, 专门翻译用户通过终端输入的语言, 并能返回结果
Linux 上最常见的是 bash(但不是唯一 还有 zsh、fish 等)
Windows 早期有 command.com 后来是 cmd 现在是 PowerShell, 甚至还能运行 Linux Shell
Terminal 是软件模拟的对话窗口 Console 更偏向物理设备

```
目前能用到的就就是
一键配置 软件运行的依赖, 环境
一键编译
批量处理文件(替换文本, 服务器测试链接)
启动任务(发送消息什么的)
```

cpp 主要写
qt 开发桌面端程序, 或者性能优化方面

java 主要写的是在服务器上运行的 
后端业务逻辑, 特点是可以接受超级无敌多的数据

powershell 就是脚本<批量处理, 配置环境, 一键编译>
python 也可以写脚本(比如鼠标点击, 键盘点击)
还有爬虫, 数据分析, 包括一些 web 开发也能写
反正啥都能写

javascripts 说是前端, 就是负责按钮逻辑什么的(按按钮之后会干啥)
和后段代码交互, 调用 api, 然后 electron 开发各种桌面端程序
然后还有前端的 css 和 html, 我感觉就是和 makrdown 坐一桌就可以了

rust 和 go 我目前根本用不到
我能理解的只有这些, 实际写项目我还是啥都不会写, 因为根本没写过, 差不多就这样



[【国语】PowerShell 实战课程 - 从入门到精通教程-自动化神器](https://www.bilibili.com/video/BV1RekHBoEAt?p=6)
1. cd(change directory) 
cd + 当前目录下文件夹 = 进入指定文件夹
cd + 路径, 同理
cd .. 退回上一级目录
cd ..\.. 退回两级别
cd ./docs/notes 自己猜

pwd(print working directory)
ls(list directory contents)

mkdir + myfolder  create a folder in current directory called "myfolder"

start + fileName

cp <源路径> <目标路径> copy

路径符号:
# 命令行路径符号速查表

| 符号 | 名称 | 含义 | 示例 | 说明 |
| :--- | :--- | :--- | :--- | :--- |
| `/` | 斜杠 (Slash) | **路径分隔符** | `C:/Project/src` | 现代系统中通用（Windows PowerShell/CMD/Linux/macOS 均支持）。 |
| `.` | 点 (Dot) | **当前目录** | `./app.exe` | 强调“当前文件夹”。运行当前目录下的程序时必须加。 |
| `..` | 双点 (Double Dot) | **上级目录** | `cd ..` | 向上退回一级文件夹。 |
| `../..` | 多级上级 | **上两级目录** | `cd ../../` | 向上退回两级文件夹。 |
| `~` | 波浪号 (Tilde) | **家目录** | `cd ~/Desktop` | 指向当前用户的个人文件夹（如 `C:\Users\YourName`）。 |
| `/` (开头) | 根目录 | **最顶层目录** | `cd /` | Linux/macOS 中表示根目录；Windows 中表示当前盘符的根目录（如 `C:\`）。 |

## 常用组合示例

| 命令 | 解释 |
| :--- | :--- |
| `cd .` | 留在当前目录（无实际操作）。 |
| `cd ..` | 进入上一级目录。 |
| `cd ../..` | 进入上两级目录。 |
| `cp file.txt ../` | 将 `file.txt` 复制到上级目录。 |
| `mv file.txt ../new_name.txt` | 将 `file.txt` 移动到上级目录并重命名。 |
| `./program` | 运行当前目录下的 `program` 程序。 |
| `ls ../../` | 列出上两级目录下的内容。 |

## 记忆口诀

*   **`/` 是路标**：分隔不同的文件夹。
*   **`.` 是脚下**：当前所在的位置。
*   **`..` 是楼上**：返回上一层。
*   **`~` 是老家**：用户的个人主目录。

> **注意**：在 Windows 的传统 CMD 中，路径分隔符通常使用反斜杠 `\`（如 `cd ..\..\bin`），但在 PowerShell 和编程中，正斜杠 `/` 通常兼容性更好。

# 把 src 文件夹完整地复制到 backup 文件夹
cp -Recurse src backup
# 简写# 命令行路径符号速查表

| 符号 | 名称 | 含义 | 示例 | 说明 |
| :--- | :--- | :--- | :--- | :--- |
| `/` | 斜杠 (Slash) | **路径分隔符** | `C:/Project/src` | 现代系统中通用（Windows PowerShell/CMD/Linux/macOS 均支持）。 |
| `.` | 点 (Dot) | **当前目录** | `./app.exe` | 强调“当前文件夹”。运行当前目录下的程序时必须加。 |
| `..` | 双点 (Double Dot) | **上级目录** | `cd ..` | 向上退回一级文件夹。 |
| `../..` | 多级上级 | **上两级目录** | `cd ../../` | 向上退回两级文件夹。 |
| `~` | 波浪号 (Tilde) | **家目录** | `cd ~/Desktop` | 指向当前用户的个人文件夹（如 `C:\Users\YourName`）。 |
| `/` (开头) | 根目录 | **最顶层目录** | `cd /` | Linux/macOS 中表示根目录；Windows 中表示当前盘符的根目录（如 `C:\`）。 |

## 常用组合示例

| 命令 | 解释 |
| :--- | :--- |
| `cd .` | 留在当前目录（无实际操作）。 |
| `cd ..` | 进入上一级目录。 |
| `cd ../..` | 进入上两级目录。 |
| `cp file.txt ../` | 将 `file.txt` 复制到上级目录。 |
| `mv file.txt ../new_name.txt` | 将 `file.txt` 移动到上级目录并重命名。 |
| `./program` | 运行当前目录下的 `program` 程序。 |
| `ls ../../` | 列出上两级目录下的内容。 |

## 记忆口诀

*   **`/` 是路标**：分隔不同的文件夹。
*   **`.` 是脚下**：当前所在的位置。
*   **`..` 是楼上**：返回上一层。
*   **`~` 是老家**：用户的个人主目录。

> **注意**：在 Windows 的传统 CMD 中，路径分隔符通常使用反斜杠 `\`（如 `cd ..\..\bin`），但在 PowerShell 和编程中，正斜杠 `/` 通常兼容性更好。
cp -r src backup

# ps grammar 
verb + noun
get-process

winget 用来联网下载软件的
curl.exe + url (curl = 命令行里的 HTTP 客户端，用来跟网址打交道——发请求、拿数据、调接口、下载文件，都能干)

哦对了 curl 在powershell 是另一个操作的别名

curl.exe​ → 真正的 curl（libcurl 那套），跨平台通用，输出是原始文本
返回的是一个 json 文件, 是网站回应给你的

curl（不带 .exe，在 PowerShell 里）​ → 是 Invoke-WebRequest的别名，输出是 PowerShell 对象

curl.exe https://api.github.com

code . ,用 vscode 打开当前文件夹
code + filename.suf 直接编写文件, 但是没保存

history 输出你之前在终端干的所有的命令

man + 你不知道的命令

echo 是 write-output 的别名
echo "hello world" 就可以直接输出 hello world



new-item + filename (创建文件)
也可以 new-item == ni (ni <Path>\<FileName>)
start + filename(打开文件)
mkdir + foldername(创建文件夹)
code + filename.suf(直接编写文件在当前目录)


$ + variable-name 创建变量来的

| 符号就是管道, 把左边输出的东西直接喂给右边

ps的 参数是啥意思
什么叫都以 - 开头
是不是参数就是 命令后面跟着的就都是参数, 和函数的传递参数的参数是一个概念
为什么说参数以 - 开头
我 echo "hello world" 的字符串是不是也是一个参数为什么没有 -


不是 那个所谓的参数
可以在参数前面加上 -官方规定的参数名字 当做形式化参数
然后后面跟上实际参数 这样操作 
这个结论是对的

powershell 的数据结构与变量
```powershell
$string = "string"
$inte = 30
$arr = 1, 2, 3, 4 
echo $arr[0]

$ump = { name1 = "yes", name2 = "no"}
echo $ump.name1
```

默变量:
  - $PSVersionTable(当前系统 powershell 的所有信息)
  - $_(当前正在处理的对象的信息)


