---
tags:
  - acm
  - tool
category: 杂项工具
source:
  - "XCPC赛场Codebook更新指南.md"
---

# XCPC赛场Codebook更新指南

## 模块名称

XCPC赛场Codebook更新指南

## 来源

- XCPC赛场Codebook更新指南.md

## 适用场景

比赛中辅助建模、优化实现或降低出错率的工具模板。

## 核心思想

XCPC赛场Codebook更新指南 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：XCPC赛场Codebook更新指南.md

# XCPC赛场Codebook更新指南

## 目标

本文档用于说明如何更新 `XCPC赛场Codebook.md`。

当前 Codebook 不是手工维护的最终文件，而是由脚本从知识库与补充模板生成：

- 知识库来源：`ACM知识库/`
- 补充来源：`ACM模板.md`
- 生成脚本：`scripts/build_xcpc_codebook.js`
- 输出文件：`XCPC赛场Codebook.md`

更新时优先修改源文件或生成脚本，再重新生成 Codebook。

---

## 目录结构

```text
算法笔记/
├── ACM模板.md
├── ACM知识库/
├── scripts/
│   └── build_xcpc_codebook.js
├── XCPC赛场Codebook.md
└── XCPC赛场Codebook更新指南.md
```

---

## 更新流程

### 1. 新增或修改普通算法模板

如果模板已经在 `ACM知识库/` 中有对应卡片：

1. 修改对应 Markdown 文件。
2. 确保文件里有代码块。
3. 运行生成脚本。

```powershell
node scripts/build_xcpc_codebook.js
```

脚本会重新生成：

```text
XCPC赛场Codebook.md
```

---

### 2. 从 ACM模板.md 补充新模板

如果 `ACM模板.md` 中有新模板，但 `ACM知识库/` 里没有：

1. 打开 `scripts/build_xcpc_codebook.js`。
2. 在 `pageMeta` 中添加模板说明：

```js
"模板名称": [
  "作用，1 句话。",
  "核心思想，1 句话。",
  "复杂度。"
],
```

3. 在 `codeOverride` 中添加标准代码：

```js
"模板名称": `代码内容`,
```

4. 如果这是手工补充页，在 `manualPages` 中添加：

```js
{
  title: "模板名称",
  category: "基础模板",
  source: "ACM模板.md",
  mistakes: ["易错点 1。", "易错点 2。"],
},
```

5. 重新生成：

```powershell
node scripts/build_xcpc_codebook.js
```

---

## 分类规则

Codebook 目前使用以下一级分类：

```text
基础模板
数据结构
图论
动态规划
数学
字符串
杂项工具
```

如果新增模板，优先放入最符合赛场检索习惯的分类。

示例：

- `快速幂`：数学
- `树状数组`：数据结构
- `拓扑排序`：图论
- `快读`：基础模板
- `对拍`：杂项工具

---

## 页码规则

页码由脚本自动生成，不要手工改 `XCPC赛场Codebook.md` 中的页码。

固定页：

```text
P001 首页目录
P002 高频必带模板 TOP 15
P003 最容易写错 TOP 10
P004 推荐使用顺序
```

算法模板页从 `P005` 开始。

每个模板页标题下都会自动生成：

```md
> 页码：Pxxx
```

目录中也会自动标注对应页码。

---

## 单页模板规范

每个算法页必须保持以下结构：

````md
# 算法名称

> 页码：Pxxx

## 作用

1-2 句话。

## 核心思想

极简竞赛版。

## 标准代码

```cpp
唯一主体代码
```

## 复杂度

O(?)

## 易错点

- 易错点 1。
- 易错点 2。
````

强约束：

- 一页只放一个算法。
- 一个算法页只保留一个主体代码块。
- 不写教程式长篇讲解。
- 多版本模板只保留赛场最稳版本，必要时写进生成脚本的 `codeOverride`。

---

## 生成后检查

生成后建议执行以下检查。

### 检查标题、页码、分页数量

```powershell
$txt=Get-Content -Raw -Encoding UTF8 'XCPC赛场Codebook.md'
'h1=' + ([regex]::Matches($txt,'(?m)^# ')).Count
'page_marks=' + ([regex]::Matches($txt,'页码：P\d{3}')).Count
'separators=' + ([regex]::Matches($txt,'(?m)^---$')).Count
'fences=' + ([regex]::Matches($txt,'```')).Count
```

正常情况下：

- `h1` 应等于 `page_marks`
- `separators` 应等于 `h1 - 1`
- `fences` 应为偶数

### 抽查目录页

```powershell
Get-Content -TotalCount 120 -Encoding UTF8 'XCPC赛场Codebook.md'
```

确认：

- 目录有页码。
- 分类页码范围正确。
- 新增模板出现在正确分类中。

---

## 常见维护场景

### 修改某个模板代码

优先改 `scripts/build_xcpc_codebook.js` 里的 `codeOverride`。

适合这种方式的模板：

- 原始 Markdown 里有多个版本。
- 原始代码不够赛场化。
- 需要统一代码风格。

### 删除不适合打印的模板

在 `skip` 集合中加入模板名：

```js
const skip = new Set([
  "模板名称"
]);
```

### 修改 TOP 15

修改 `highTop` 数组。

### 修改易错 TOP 10

修改 `wrongTop` 数组。

### 修改推荐使用顺序

修改脚本中生成 `推荐使用顺序` 的文本。

---

## 注意事项

- 不建议直接手改 `XCPC赛场Codebook.md`，重新生成后会被覆盖。
- 新增模板后一定要重新生成，页码才会同步更新。
- 如果某个 Markdown 文件里有多个算法，应拆成多个页，或在生成脚本中单独加入手工页。
- 如果源模板有多个代码块，脚本默认取第一个；需要指定最稳版本时，用 `codeOverride`。
```

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[ACM综合模板]]
[[随机]]
