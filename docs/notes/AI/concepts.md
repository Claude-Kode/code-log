[OpenCode详细攻略，开源版Claude Code，免费模型与神级插件](https://www.bilibili.com/video/BV1BVrXBUEbR/)

对。在项目根目录建 .opencode/ 文件夹，可以放项目级别的配置：
my-project/
└── .opencode/
    ├── opencode.json        ← 项目配置，与全局 deep-merge，项目覆盖全局
    ├── agent/
    │   └── review.md        ← 项目专属 agent
    ├── command/
    │   └── deploy.md        ← 项目专属 / 命令
    ├── skills/
    │   └── my-skill/SKILL.md
    └── plugin/
        └── my-plugin.ts

好的，我将原文档重新排版为结构清晰、代码块格式规范的 Markdown 版本。所有配置示例均使用 `json` 语法高亮，并保留完整的字段说明。

---

# opencode 配置完全指南

## 一、配置存放位置

| 配置种类 | 项目级路径 | 全局级路径 |
|---------|-----------|-----------|
| 主配置 | `./opencode.json` | `~/.config/opencode/opencode.json` |
| Agent 定义 | `.opencode/agent/<name>.md` | `~/.config/opencode/agent/<name>.md` |
| Command 定义 | `.opencode/command/<name>.md` | `~/.config/opencode/command/<name>.md` |
| Skill 定义 | `.opencode/skill/<name>/SKILL.md` | `~/.config/opencode/skill/<name>/SKILL.md` |
| 指令文件 | 任意路径（在 `instructions` 中引用） | 任意路径（在 `instructions` 中引用） |
| 插件 | `.opencode/plugin/<name>.ts` | 全局也扫描对应路径 |

**合并规则**：项目级和全局级配置会**深度合并**，项目配置覆盖全局配置。

---

## 二、opencode.json 所有字段详解

### 1. 基础设置

```json
{
  "$schema": "https://opencode.ai/config.json",   // 编辑器自动补全和校验
  "model": "anthropic/claude-sonnet-4-6",          // 默认主模型（格式: provider/model-id）
  "small_model": "anthropic/claude-haiku-3-5",     // 轻量模型，用于标题生成等简单任务
  "default_agent": "build",                        // 默认 agent，必须是 primary 模式
  "username": "my-name",                           // 对话中显示的用户名
  "shell": "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe",  // bash 工具使用的 shell
  "logLevel": "INFO"                               // 日志级别: DEBUG | INFO | WARN | ERROR
}
```

**作用**：控制模型、用户身份、shell 环境等基础行为。

---

### 2. `instructions` —— 全局指令文件

```json
{
  "instructions": ["AGENTS.md", "CHINESE.md", "docs/rules.md"]
}
```

**作用**：列出的文件内容自动注入到每轮对话的系统提示中，作为不可变的全局行为约束。  
**与 skill 的区别**：
- `instructions` → 每次都生效，适合“始终用中文”这类铁律。
- `skill` → 系统根据任务描述自动匹配，条件生效，适合领域知识。

---

### 3. `agent` —— 自定义代理

**两种定义方式：**

**方式一：内联在 opencode.json 中**

```json
{
  "agent": {
    "code-reviewer": {
      "model": "anthropic/claude-sonnet-4-6",
      "mode": "subagent",                    // primary | subagent | all
      "description": "Review code changes and suggest improvements",
      "permission": {
        "edit": "deny",                      // 子 agent 不能改代码
        "bash": "ask",                       // 执行命令需要征求同意
        "read": "allow"                      // 可以任意读文件
      },
      "temperature": 0.3,
      "color": "#00FF88",
      "steps": 20,                           // 最大迭代步数
      "hidden": false,                       // 是否在 @ 菜单中隐藏
      "prompt": "You are a strict code reviewer."
    }
  }
}
```

**方式二：文件定义** `.opencode/agent/code-reviewer.md`

```markdown
---
description: Review code changes and suggest improvements
mode: subagent
model: anthropic/claude-sonnet-4-6
permission:
  edit: deny
  bash: ask
  read: allow
temperature: 0.3
color: "#00FF88"
steps: 20
---

You are a strict code reviewer. Focus on:
1. Correctness and edge cases
2. Performance implications
3. Code style consistency
```

**作用**：定义多个角色不同的 agent，通过 `@name` 或 `default_agent` 切换使用。  
opencode 内置了 `build`、`plan`、`general`、`explore` 四个主 agent 和 `title`、`summary`、`compaction` 三个内部 agent，你可以覆盖或禁用它们：

```json
{
  "agent": {
    "build": { "model": "anthropic/claude-sonnet-4-6" },
    "plan": { "disable": true }
  }
}
```

---

### 4. `command` —— 自定义 `/` 命令

**两种定义方式：**

**方式一：内联**

```json
{
  "command": {
    "deploy": {
      "description": "Deploy the application to production",
      "template": "Deploy the application. Branch: $1. $ARGUMENTS",
      "agent": "code-reviewer",
      "model": "anthropic/claude-sonnet-4-6",
      "subtask": true     // true = 作为子任务在当前对话中执行，false = 新对话
    }
  }
}
```

**方式二：文件定义** `.opencode/command/deploy.md`

```markdown
---
description: Deploy the application to production
agent: code-reviewer
model: anthropic/claude-sonnet-4-6
subtask: true
---

Deploy the application. Branch: $1. $ARGUMENTS
```

**作用**：通过 `/deploy` 手动触发快捷操作。`$ARGUMENTS` 替换为用户输入的全文，`$1`、`$2` 替换为第 1、2 个参数。

---

### 5. `skills` —— 技能路径配置

```json
{
  "skills": {
    "paths": [
      ".opencode/skills",
      "~/.config/opencode/skills"
    ],
    "urls": [
      "https://example.com/.well-known/skills/"
    ]
  }
}
```

**作用**：告诉 opencode 去哪里扫描 skill 定义文件（`**/SKILL.md`）。Skill 本身是一个带 `description` 的 Markdown 文件，系统会根据任务描述自动匹配并注入。

**Skill 文件示例**：`.opencode/skills/my-skill/SKILL.md`

```markdown
---
name: my-skill
description: Use when working with database migrations or schema changes
---

# My Skill

Instructions and knowledge for this domain...
```

---

### 6. `permission` —— 权限规则

```json
{
  "permission": {
    "edit": "deny",                            // 全局禁止编辑文件
    "bash": {                                  // 按命令模式配置
      "git *": "allow",
      "rm *": "deny",
      "*": "ask"                               // 其他命令每次询问
    },
    "read": "allow",                           // 读文件总是允许
    "websearch": "ask",                        // 网络搜索需要询问
    "external_directory": {
      "~/secrets/**": "deny",
      "*": "allow"
    }
  }
}
```

**作用**：控制 agent 能做什么、不能做什么。细粒度到每个工具、每个 glob 模式。per-agent 的权限会覆盖全局权限。  
**支持的权限键**：`read`、`edit`、`glob`、`grep`、`list`、`bash`、`task`、`external_directory`、`todowrite`、`question`、`webfetch`、`websearch`、`lsp`、`doom_loop`、`skill`。

---

### 7. `provider` —— 模型供应商配置

```json
{
  "provider": {
    "anthropic": {
      "options": {
        "apiKey": "sk-ant-...",
        "baseURL": "https://...",
        "timeout": 120000,
        "setCacheKey": true                    // 启用 prompt caching
      }
    },
    "openai": {
      "options": {
        "apiKey": "sk-...",
        "baseURL": "https://api.openai.com/v1"
      },
      "models": {
        "gpt-4o": {
          "cost": { "input": 2.5, "output": 10 },
          "limit": { "context": 128000, "output": 4096 }
        }
      }
    }
  },
  "disabled_providers": ["copilot"],
  "enabled_providers": ["anthropic", "openai"]   // 只启用这些 provider
}
```

**作用**：配置 API Key、Base URL、超时、模型价格覆盖等。`enabled_providers` 设置后只启用指定的 provider。

---

### 8. `mcp` —— MCP 工具服务器

```json
{
  "mcp": {
    "playwright": {
      "type": "local",
      "command": ["npx", "-y", "@playwright/mcp"],
      "enabled": true,
      "cwd": ".",
      "environment": { "BROWSER": "chromium" },
      "timeout": 10000
    },
    "github-api": {
      "type": "remote",
      "url": "https://mcp.example.com/github",
      "enabled": true,
      "headers": {
        "Authorization": "Bearer {env:GITHUB_TOKEN}"
      },
      "oauth": {
        "clientId": "..."
      }
    },
    "old-server": { "enabled": false }          // 禁用继承来的
  }
}
```

**作用**：接入外部工具服务器，让 agent 获得浏览器控制、数据库查询等能力。

---

### 9. `plugin` —— 插件

```json
{
  "plugin": [
    "opencode-gemini-auth",                     // npm 包（最新版）
    "opencode-foo@1.2.3",                       // npm 包（固定版本）
    "./local-plugin.ts",                        // 本地文件
    "file:///abs/path/plugin.js",               // 绝对路径 URL
    ["opencode-bar", { "option": "value" }]     // 元组形式传 options
  ]
}
```

**作用**：扩展 opencode 的能力，可以 hook 工具执行前后、消息转换、配置修改等生命周期。  
**自动发现**：`.opencode/plugin/*.ts` 或 `*.js` 也会自动加载。

---

### 10. `references` —— 外部引用

```json
{
  "references": {
    "docs": {
      "path": "../product-docs",
      "description": "Use for product behavior and terminology"
    },
    "sdk": {
      "repository": "owner/sdk",
      "branch": "main",
      "description": "Use for SDK implementation details",
      "hidden": true
    },
    "notes": "~/Documents/notes"               // 字符串简写
  }
}
```

**作用**：将本地目录或 Git 仓库注册为可引用资源。只有带 `description` 的条目会被推荐给 agent。agent 通过 `@docs`、`@sdk` 等方式引用。

---

### 11. `formatter` —— 格式化工具

```json
{
  "formatter": true,                            // 启用内置 formatter
  // 或
  "formatter": {
    "python": {
      "command": ["ruff", "format", "--stdin-filename", "{filename}"],
      "extensions": [".py"],
      "environment": {}
    }
  }
}
```

**作用**：控制代码格式化。`false` 禁用，`true` 启用内置，或配置自定义 formatter。

---

### 12. `lsp` —— 语言服务器

```json
{
  "lsp": true,                                  // 启用内置 LSP
  // 或
  "lsp": {
    "typescript": {
      "command": ["node", "node_modules/.bin/typescript-language-server", "--stdio"],
      "extensions": [".ts", ".tsx", ".js", ".jsx"],
      "env": {},
      "initialization": {}
    }
  }
}
```

**作用**：启用 LSP 提供语义级代码分析。

---

### 13. `compaction` —— 上下文压缩

```json
{
  "compaction": {
    "auto": true,                               // 自动在上下文满时压缩
    "tail_turns": 3,                            // 保留最近几轮对话原文
    "preserve_recent_tokens": 8000,             // 保留最近多少 token 原文
    "reserved": 4000,                           // 保留的 token 缓冲
    "prune": false                              // 是否裁剪旧工具输出
  }
}
```

**作用**：控制长对话时的上下文压缩策略，避免模型“忘记”早期内容。

---

### 14. 其他实用字段

```json
{
  "autoupdate": true,                           // 自动更新: true | false | "notify"
  "snapshot": true,                             // 启用快照（支持 undo）
  "share": "manual",                            // 分享: manual | auto | disabled
  "tool_output": {
    "max_lines": 2000,                          // 工具输出截断行数
    "max_bytes": 51200                          // 工具输出截断字节数
  },
  "attachment": {
    "image": {
      "auto_resize": true,
      "max_width": 2000,
      "max_height": 2000,
      "max_base64_bytes": 5242880
    }
  },
  "experimental": {
    "primary_tools": ["edit"],                  // 只有主 agent 能用这些工具
    "mcp_timeout": 30000,
    "batch_tool": true,                         // 启用批量工具
    "continue_loop_on_deny": true               // 权限被拒时继续循环
  }
}
```

---

## 三、推荐的“充分发挥模型能力”配置方案

这是一个最大化模型性能的项目级 `opencode.json` 示例：

```json
{
  "$schema": "https://opencode.ai/config.json",

  "model": "anthropic/claude-sonnet-4-6",
  "small_model": "anthropic/claude-haiku-3-5",

  "instructions": ["AGENTS.md", "CHINESE.md"],

  "agent": {
    "build": {
      "model": "anthropic/claude-sonnet-4-6",
      "permission": {
        "bash": { "git *": "allow", "npm *": "allow", "cargo *": "allow", "*": "ask" },
        "edit": "allow",
        "read": "allow",
        "websearch": "ask",
        "webfetch": "allow"
      }
    },
    "reviewer": {
      "mode": "subagent",
      "model": "anthropic/claude-sonnet-4-6",
      "temperature": 0.2,
      "permission": { "read": "allow", "edit": "deny", "bash": "deny" },
      "description": "Read-only code reviewer. Use @reviewer for PR review and code analysis.",
      "prompt": "You are a thorough code reviewer. Analyze correctness, performance, security, and maintainability. Provide actionable feedback."
    },
    "explorer": {
      "model": "anthropic/claude-haiku-3-5",
      "temperature": 0,
      "description": "Fast codebase explorer. Used automatically for file search tasks."
    }
  },

  "permission": {
    "bash": { "git *": "allow", "*": "ask" },
    "edit": "allow",
    "read": "allow",
    "external_directory": { "*": "allow" }
  },

  "compaction": {
    "auto": true,
    "tail_turns": 5,
    "preserve_recent_tokens": 12000
  },

  "tool_output": {
    "max_lines": 3000,
    "max_bytes": 102400
  }
}
```