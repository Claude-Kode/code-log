好的，下面是 `.gitignore` 文件编写规则的完整指南。

---

## `.gitignore` 编写规则

### 1. 规则生效范围

- `.gitignore` 文件可以放在项目根目录或任何子目录。
- 每行一条规则，影响当前目录及所有子目录中的文件。
- 规则对**已经跟踪的文件无效**（先 `git rm --cached` 取消跟踪才能忽略）。

---

### 2. 基础模式语法

| 模式 | 含义 | 示例 |
|------|------|------|
| `*.ext` | 匹配所有扩展名为 `.ext` 的文件 | `*.log` — 忽略所有日志文件 |
| `?` | 匹配任意单个字符 | `???.tmp` — 忽略所有三个字符名的临时文件 |
| `[abc]` | 匹配方括号内的任一字符 | `temp[0-9].txt` — 忽略 `temp1.txt` 到 `temp9.txt` |
| `[0-9]` | 匹配数字范围 | `img[0-9][0-9].png` — 忽略 img00.png 到 img99.png |
| `**` | 递归匹配零个或多个目录 | `**/temp/` — 忽略所有子目录中名为 `temp` 的文件夹 |

---

### 3. 目录 vs 文件

- **以 `/` 结尾** — 只匹配目录，不匹配普通文件  
  `build/` — 忽略名为 `build` 的目录，不会忽略同名文件
- **不以 `/` 结尾** — 同时匹配文件和目录  
  `build` — 忽略名为 `build` 的文件和目录

---

### 4. 路径锚定

- **以 `/` 开头** — 相对于 `.gitignore` 所在目录匹配  
  `/.env` — 只忽略根目录下的 `.env`，不忽略 `subdir/.env`
- **不以 `/` 开头** — 可以出现在任意层级  
  `.env` — 忽略项目内所有 `.env` 文件
- **中间有 `/`** — 同样相对于 `.gitignore` 目录  
  `src/output/*.o` — 只忽略 `src/output/` 下的 `.o` 文件

---

### 5. 反选（Negation）

- `!` 开头 — 重新包含被前一条规则忽略的文件  
  ```
  *.log
  !important.log
  ```
  忽略所有 `.log`，但保留 `important.log`

- 注意：如果父目录已被忽略，反选无效  
  ```
  build/
  !build/important.log
  ```
  错误，因为 `build/` 整个被忽略了，内部文件不会被检查  
  正确做法：
  ```
  build/*
  !build/important.log
  ```

---

### 6. 注释

- `#` 开头的行为注释（`#` 必须在行首，或前面只有空格）
- 如果文件名确实以 `#` 开头，需要转义：`\#foo`  
  ```
  # 这是注释
  *.pyc           # 行尾注释也行
  \#myfile#       忽略名字带 # 的文件
  ```

---

### 7. 全局忽略

- `git config --global core.excludesFile ~/.gitignore_global`  
- 对所有 Git 仓库生效，适合放 OS 或 IDE 相关的忽略项（如 `.DS_Store`、`Thumbs.db`）

---

### 8. 常用技巧

#### 忽略文件夹但保留特定文件

```
logs/*
!logs/.gitkeep
```

#### 忽略文件夹中所有内容但不忽略文件夹本身（Git 不会跟踪空目录）

```
logs/*
```

#### 忽略除特定扩展名外的所有文件

```
*
!*.cpp
!*.h
!*.md
```

#### 使用绝对路径忽略（多级 `.gitignore`）

在 `docs/` 目录下新建一个 `.gitignore`：
```
*.pdf
```
则只忽略 `docs/` 内的 PDF 文件，不影响根目录。

---

### 9. 一条规则匹配多个文件

- `*.exe` 匹配 `app.exe`、`bin/tool.exe` 等所有目录下的可执行文件
- `build/` 匹配所有名为 `build` 的目录，无论在哪一层

---

### 10. 调试 `.gitignore`

想知道某个文件为什么被忽略或未被忽略：

```bash
git check-ignore -v 文件名
```

例如：
```bash
git check-ignore -v build/temp.o
```
会输出 `build/.gitignore:1:*.o build/temp.o`，告诉你哪条规则匹配了哪个文件。

---

### 11. `.gitignore` 的优先级

1. 命令行中 `--assume-unchanged` / `--skip-worktree`
2. 当前目录的 `.gitignore`
3. 上级目录的 `.gitignore`（越近的越优先）
4. 仓库中的 `.git/info/exclude`
5. 全局忽略文件

同一文件如果被多个模式匹配，**最后匹配到的模式决定**是否忽略。所以反选通常在具体忽略规则之后。

---

掌握了这些，你就能写出精确而简洁的 `.gitignore` 了。需要我帮你定制一份更贴合你项目的吗？