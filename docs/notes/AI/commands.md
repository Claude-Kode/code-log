可以新建 `commands.md`

好，那我给你一个「中等长度、信息密度高」的版本，不长篇大论，但把细节补齐👇

一、放哪？（路径与优先级）

自定义命令就是 .md 文件，放两个地方：
1. 全局（所有项目都能用）
   • `Windows: C:\Users\lzryy\.config\opencode\commands\summarize.md`

   • 适合：通用操作，如 `/commit、/review`

2. 项目级（仅当前项目，可提交 Git）
   • 项目根目录：`.opencode\commands\deploy.md`

   • 适合：项目特有流程，如 `/deploy-staging`

优先级：项目级 > 全局（同名时项目级覆盖）。

二、MD 文件怎么写？（核心结构）

一个命令文件 = `Frontmatter`（头信息） + 正文（Prompt）

1.  `Frontmatter`（必填，用 --- 包裹）

```
---
description: 生成符合 Conventional Commits 的提交信息（必填，/补全时显示）
agent: build        # 可选：指定用 build/plan 模式
model: deepseek/deepseek-v4-flash  # 可选：指定模型
---
```

• `description`：一定要写清楚，否则你自己都会忘这个命令干嘛用。

• `agent`：解释代码用 `plan`（只读），改代码用 `build`（读写）。

• `model`：简单任务（如总结）指定 `Flash`，省钱。

2. 正文（必填，就是你的 Prompt）

请根据 Git 暂存区的改动生成提交信息，要求：
1. 格式：`type(scope): subject`
2. `type` 只能选 `feat/fix/docs/style/refactor/test/chore`
3. `subject` 不超过 50 字符，结尾无句号
4. 复杂改动需在空一行后写 `body` 说明原因

关键语法：`$ARGUMENTS`
用于接收你输入命令后的参数，例如：
解释 `$ARGUMENTS` 文件的核心逻辑和潜在 Bug。

调用：`/explain src/utils/auth.ts`

三、生效与使用

• 必须重启：`OpenCode` 启动时加载命令，新建/修改后需重启 `TUI`。

• 自动补全：输入 / 即可看到所有命令，`description` 会显示在旁边。

• 手动调用：直接输入 `/command-name arg1 arg2`

四、千万别搞混（命令 vs Skills vs AGENTS.md）

类型 触发方式 核心作用 例子

命令 你主动输入 /xxx 快捷操作，解决重复劳动 /commit 生成提交信息

Skills AI 自动匹配或你指定 领域知识包，教 AI 怎么做专家级任务 frontend-design 技能

AGENTS.md AI 自动遵守 项目通用规则，AI 的“入职手册” 项目技术栈、代码规范

一句话记：命令是你喊 AI 干活，Skills 是 AI 的专项技能书，AGENTS.md 是 AI 的员工守则。

五、最佳实践（避坑指南）

1. 命名规范：文件名即命令名，用英文、连字符（如 generate-commit.md），避免 Windows 路径问题。
2. 勤加描述：description 写清楚，否则命令多了自己都懵。
3. 善用参数：复杂操作拆解为 $ARGUMENTS，让命令更灵活。
4. 分离关注点：复杂逻辑（如代码审查标准）放进 Skills，命令里只做调度，好维护。
5. 定期清理：没用的命令删掉，保持 / 补全列表清爽。

六、一个完整示例（直接可用）

全局命令：`generate-commit.md`
```
---
description: 生成符合 Conventional Commits 规范的提交信息
agent: plan
model: deepseek/deepseek-v4-flash
---
```
请根据当前 `Git` 暂存区的改动，生成提交信息：
1. 格式：`type(scope): subject`
2. `type` 限定为 `feat/fix/docs/style/refactor/test/chore`
3. `scope` 为受影响模块（如 auth/api）
4. `subject ≤ 50` 字符，无结尾句号
5. 必要时空一行后写 `body` 说明动机和影响

调用: `/generate-commit`

这样长度刚好，既有骨架又有血肉，实际操作足够了。需要我再针对某个点（比如如何把现有 Skills 关联到命令里）展开一点吗？