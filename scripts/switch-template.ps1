# param 是用来声明这个脚本运行需要什么变量的
# PowerShell 解析这行代码的逻辑是从右向左的
# [string] 是类型转换, [ValidateSet("cpp","py")] 是变量约束
param([ValidateSet("cpp","py")][string]$lang)
# lang 是 language 的缩写

$cphrcPath = "C:\Code\AlgorithmSolves\.cphrc"
# Get-Content 会返回一个字符串数组, 每一行是一个数组元素
# -Raw 它会把整个文件内容当成一个完整的字符串返回, 保留换行符, 但不拆分成数组
# ConvertFrom-Json 是把 json 转换成 powershell 对象, 注意单词 Convert'From'
$config = Get-Content $cphrcPath -Raw | ConvertFrom-Json

# 意思就是: 读取文件得到 JSON 字符串 → 转成对象存到 $config
# 之后你就可以用 $config.languages.cpp.templateFile 这样的方式访问和修改属性了

# -eq 是比较运算符

# 运算符	含义
# -eq	等于 (equal)
# -ne	不等于 (not equal)
# -gt	大于 (greater than)
# -lt	小于 (less than)
# -like	通配符匹配

if ($lang -eq "cpp") {
    $config.languages.cpp.templateFile = "C:\Code\AlgorithmSolves\templates\TEMPLATE-2.cpp"
} else {
    $config.languages.cpp.templateFile = "C:\Code\AlgorithmSolves\templates\TEMPLATE-PY.py" # 假设py也有对应配置
}

# -Depth 控制对象嵌套深度的(json 字符串里面的)
# Set-Content 把左边接受到的 JSON 字符串写入文件, 覆盖原内容 并用 UTF-8 编码
# UTF-8 是为了避免乱码或者中文
$config | ConvertTo-Json -Depth 10 | Set-Content $cphrcPath -Encoding UTF8
# config 是 configuration(配置) 的缩写
Write-Host "Template switched. Please re-run CPH."