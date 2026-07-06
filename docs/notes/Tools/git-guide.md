# Git 完全学习指南
> 这是一个为自己的 `code-log` 整理的 Git 全流程学习笔记。
> 理解 Git 的核心在于理解它的 **区域模型**。

## 1. Git 的三大核心区域（The Three States）

这是理解 Git 最重要的概念。任何一个被跟踪的文件，在你的电脑上总是处于这三种状态之一：

```
[ 工作目录  ]  --(git add)-->  [ 暂存区   ]  --(git commit)--> [ 本地仓库 ]
(Working Dir)                  (Stage/Index)                 (Repository)

[ 本地仓库 ]  --(git push)-->  [ 远程仓库 ]
                               (Remote, e.g., GitHub)
```

| 中文名 | 英文名 | 作用 | 你的操作 |
|---|---|---|---|
| **工作目录** | Working Directory | 你实际看到的文件夹和文件，修改代码的地方。 | 编辑、新增、删除文件。 |
| **暂存区** | Stage / Index | 一个“购物车”，准备下一次提交的快照。 | `git add` 就是把修改放入购物车。 |
| **本地仓库** | Repository | 存储所有版本历史的地方（那个隐藏的 `.git` 文件夹）。 | `git commit` 就是把购物车里的东西永久保存到历史。 |
| **远程仓库** | Remote | 备份在 GitHub / GitLab 等服务器上的完整仓库。 | `git push` / `git pull`。 |

**关键理解**：`git add` 和 `git commit` 是两个完全独立的步骤。你可以多次 `add`，然后一次性 `commit`。

## 2. Git 工作流全流程（从 0 到 1）

### 场景：你刚刚初始化仓库，或者克隆了一个仓库。
```bash
# 1. 查看当前状态（最常用的指令，没有之一）
git status

# 2. 查看具体修改了什么内容
git diff

# 3. 将修改的文件添加到“暂存区”
git add <文件名>           # 添加单个文件
git add .                  # 添加所有变更（新增、修改、删除）

# 4. 提交，形成一个版本快照
git commit -m "提交说明"   # 简短说明做了什么
git commit -m "标题" -m "详细描述"  # 更规范的写法

# 5. 查看提交历史
git log
git log --oneline          # 一行显示一条记录
git log --oneline --graph  # 用 ASCII 画图显示分支情况
```

### 场景：推送到远程仓库 GitHub
```bash
# 1. 关联远程仓库（只需要做一次）
git remote add origin <你的GitHub仓库地址>

# 2. 把本地 main 分支推送到远程 origin
git push -u origin main    # -u 是建立关联，以后直接 git push 就行
```

## 3. 常用指令详解

### 3.1 状态与历史

| 命令 | 作用 |
|---|---|
| `git status` | 查看哪些文件被修改了，哪些在暂存区。绿色是已经 `add` 的，红色是还没 `add` 的。 |
| `git log` | 查看提交历史。按 `q` 退出。 |
| `git log --oneline --graph --all` | 缩略图看整个仓库历史，非常适合理清分支结构。 |
| `git diff` | 查看“工作目录”和“暂存区”的区别，也就是还没 `add` 的修改内容。 |
| `git diff --staged` | 查看“暂存区”和“最新一次提交”的区别，也就是即将被提交的内容。 |

### 3.2 撤销与修复（救命指令）

| 命令 | 作用 |
|---|---|
| `git restore <文件>` | **丢弃工作区的修改**。也就是把文件恢复到上次 `commit` 或 `add` 时的样子。 |
| `git restore --staged <文件>` | **从暂存区移除**，但保留你写的代码。 (新版本 Git 的命令) |
| `git reset HEAD <文件>` | 同上，把文件从暂存区拿出来。 (旧版本 Git 的命令，效果一样) |
| `git checkout -- <文件>` | 老版本 Git 恢复工作区文件的方法，和 `git restore <文件>` 一样。 |
| `git reset --soft HEAD~1` | 撤销上一次 `commit`，但所有代码修改**保留**在暂存区。 |
| `git reset --hard HEAD~1` | 彻底回退到上一次提交，且**丢弃**这之间的所有代码修改。（危险！想好再用） |

### 3.3 分支（Branch）—— Git 的灵魂

分支让你可以并行开发不同功能，互不干扰。

| 命令 | 作用 |
|---|---|
| `git branch` | 查看本地所有分支，前面带 `*` 的是你当前所在分支。 |
| `git branch <分支名>` | 创建一个新分支，但**不切换到**新分支。 |
| `git checkout <分支名>` | 切换到一个已有的分支。 |
| `git switch <分支名>` | 新版本 Git 中推荐切换分支的指令（更直观）。 |
| `git checkout -b <分支名>` | 创建一个新分支，并立刻切换到新分支。 |

```bash
# 实际开发中常见的流程：
git checkout -b feature-login    # 1. 新建并切换到 feature-login 分支
git add .                        # 2. 写代码、添加
git commit -m "完成登录UI"       # 3. 提交
git checkout main                # 4. 切回 main 分支
git merge feature-login          # 5. 把 feature-login 合并到 main 里
git branch -d feature-login      # 6. 删除已完成的分支
```

### 3.4 远程协作

| 命令 | 作用 |
|---|---|
| `git clone <仓库地址>` | 下载整个远程仓库到本地。 |
| `git push` | 把本地的新提交推送到远程仓库。 |
| `git pull` | 从远程仓库拉取最新代码，并**自动尝试合并**到你当前分支。<br>它相当于 `git fetch` + `git merge`。 |
| `git fetch` | 只拉取最新代码到本地仓库，但不合并到你的工作目录。给你一个“检查看看”的机会。 |

### 3.5 储藏（Stash）—— 临时保存工作现场

当你代码写一半，突然需要切换分支修 bug，但又不想现在就 commit。
```bash
git stash          # 把当前所有未提交的修改“藏”起来
git checkout bugfix-branch   # 去别的分支修 bug
git checkout main # 切回来
git stash pop      # 把藏起来的修改恢复出来
```

## 4. 极简日常工作流（铁三角）

当你每天编码时，只需要循环这三个步骤：

1. **写点代码 / 修改文件**
2. `git add .` （把修改放入“购物车”暂存区）
3. `git commit -m "写清楚改了什么"` （下单，永久保存进历史）

> **绝对不要**把 `git add .` 和 `git commit` 做成一个习惯性的连招（很多新手都这么干）。养成好习惯：**提交前用 `git status` 确认一下有哪些修改，用 `git diff` 确认一下改了什么**，写一个有意义的中文或英文注释，再提交。

## 5. 小抄（Cheat Sheet）

| 我该做什么 | 该打的指令 |
|---|---|
| 刚刚写完了代码，要保存版本 | `git add . && git commit -m "完成了xxx页面"` |
| 刚才提交错了，想修改最后一次的注释 | `git commit --amend -m "新的注释"` |
| 手滑把文件改错了，想回到上次保存的样子 | `git restore 文件名` |
| 代码写到一半，要切到别的分支修 bug | `git stash` -> `git checkout xxx` -> 修完回来 -> `git checkout 原分支` -> `git stash pop` |
| 推送前一天写的所有代码到 GitHub | `git push` |
| 看看别人都提交了什么 | `git log` 或者 `git log --oneline` |
| 查看完整的改动对比 | `git diff` |


这个 Markdown 文本框你可以直接贴到你的 README.md / docs/ / Obsidian / 笔记里，用来给自己或别人解释这一套命令 👇  
风格偏「教程向」，清晰、不啰嗦、带一点工程师味道。

初始化并上传一个新仓库（命令详解）

echo "# code-log" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/GoryKCY/code-log.git
git push -u origin main


逐行解释

命令 作用

echo "# code-log" >> README.md 创建（或追加）一个 README.md，写入一级标题

git init 初始化一个空的 Git 仓库（生成 .git 目录）

git add README.md 将 README.md 加入暂存区，准备提交

git commit -m "first commit" 在本地仓库创建第一个提交（commit）<br>👉 此时 Git 会自动创建当前分支

git branch -M main 将当前分支强制重命名为 main，与 GitHub 默认分支保持一致

git remote add origin <url> 将本地仓库关联到远程 GitHub 仓库，别名为 origin

git push -u origin main 将本地 main 分支推送到 GitHub<br>👉 -u 建立追踪关系，之后只需 git push

关键认知（很重要）

• ✅ 分支是在第一次 git commit 时自动创建的

• ✅ git branch -M main 不是创建分支，而是改名

• ✅ git commit 只在本地保存版本，不上传

• ✅ 真正“上传”的动作是 git push

# 新仓库初始化速查

git init                 # 初始化仓库
git add README.md        # 加入文件
git commit -m "first commit"  # 第一次提交（自动创建分支）
git branch -M main       # 重命名为 main
git remote add origin <url>    # 关联 GitHub
git push -u origin main  # 首次推送

