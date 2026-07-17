skill 就是持久性的 prompt 
opencode 的 skills 可以放在全局 & 项目
优先级 项目 > 全局
skills 的格式
```
xxx-skill/
├── SKILL.md      # 固定格式：frontmatter(name/description) + 指令正文
├── scripts/      # 可选
├── references/   # 可选
└── assets/       # 可选
```

有四种拉取 skill 的方式

| 建造方式 | 入口 | 适合场景 |
| --- | --- | --- |
| npx skills add | 命令行，从 GitHub / skills.sh 拉现成 | 装通用技能（Cloudflare、Replicate、frontend-design） |
| 手写 SKILL.md | 手动建文件夹 + 写 md | 项目级独家技能，你知道 exactly 要写啥 |
| skill-creator 技能 | 在 OpenCode 里聊完一段工作流，说"把这个做成 skill" | 从实战中沉淀，让 Agent 帮你反推 SKILL.md 草稿 |
| /skill命令（如果有的话） | TUI 内交互式创建 | 快速起手，跟 skill-creator 类似但更轻 |

最后的格式也是一样的