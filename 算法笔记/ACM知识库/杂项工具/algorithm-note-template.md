---
tags:
  - acm
  - tool
category: 杂项工具
source:
  - "skills/write-xcpc-template/assets/algorithm-note-template.md"
---

# algorithm-note-template

## 模块名称

algorithm-note-template

## 来源

- skills/write-xcpc-template/assets/algorithm-note-template.md

## 适用场景

比赛中辅助建模、优化实现或降低出错率的工具模板。

## 核心思想

algorithm-note-template 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：skills/write-xcpc-template/assets/algorithm-note-template.md

# <算法名>

## 定义

<用 1 至 3 句话说明用途、适用前提和复杂度。>

## 实现

<简述核心状态、不变量、转移或维护方式。>

### 代码

```cpp
<可复用 C++20 代码>
```

### 例题链接

<可靠链接；没有则删除本行并保留空小节。>

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[ACM综合模板]]
[[随机]]
