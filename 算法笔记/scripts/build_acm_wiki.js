const fs = require("fs");
const path = require("path");

const root = process.cwd();
const outRoot = path.join(root, "ACM知识库");

const skipNames = new Set(["创建链接.md", "欢迎.md"]);
const skipDirs = new Set([".git", ".obsidian", "ACM知识库", "scripts"]);

const categoryOrder = [
  "00 总览",
  "数据结构",
  "图论",
  "动态规划",
  "字符串",
  "数论",
  "计算几何",
  "杂项工具",
  "题单与索引",
  "知识库维护",
];

const top15 = [
  ["线段树", "区间查询/修改的核心模板；pushdown、区间边界和 Info 合并最容易在 10 分钟内写错。"],
  ["并查集", "连通性、最小生成树、离线合并的基础；注意路径压缩和可撤销版本不能混用。"],
  ["Dijkstra 算法", "非负权单源最短路首选；比赛里最容易漏 long long 和堆中过期状态判断。"],
  ["LCA", "树上距离、树上差分、虚树、路径查询的入口模板。"],
  ["KMP算法", "单模式串匹配和 border/周期问题基础；next 数组下标要统一。"],
  ["字符串哈希", "字符串判等、回文、LCP、去重常用；注意随机 base、双哈希和溢出策略。"],
  ["Dinic", "最大流标准版；分层图 BFS 与当前弧优化必须稳定。"],
  ["费用流", "最小费用最大流/费用最优匹配；势能优化和负边初始化要谨慎。"],
  ["01背包问题", "DP 入门高频；一维优化时容量必须倒序。"],
  ["完全背包问题", "无限件模型；一维优化时容量必须正序。"],
  ["多重背包问题的二进制优化", "多重背包常用优化；拆包后转 01 背包。"],
  ["最小生成树", "Kruskal/Prim 基础；与并查集、Kruskal 重构树联动。"],
  ["AC自动机", "多模式串匹配；fail 树贡献统计经常需要拓扑/DFS 汇总。"],
  ["快速数论变换（NTT）", "卷积整数模意义下的标准模板；原根、模数和 bit-reversal 易错。"],
  ["计算几何", "点线段圆基础；eps、叉积方向和边界判定决定成败。"],
];

const commonWrong = [
  ["线段树 pushdown 顺序错误", "递归前忘记下放懒标记，或 tag 清零位置不对。"],
  ["Dijkstra 用 int 存距离", "边权和路径长度可能爆 int，优先使用 long long/INF=4e18。"],
  ["SPFA 当作万能最短路", "无负权图优先 Dijkstra；SPFA 最坏 O(nm)，还要负环计数。"],
  ["背包一维循环方向反了", "01 背包倒序，完全背包正序，多重拆包后按 01 背包倒序。"],
  ["并查集可撤销版本路径压缩", "回滚 DSU 不能路径压缩，只能启发式合并并记录栈。"],
  ["字符串哈希变量名/base 不一致", "模板中 base/bs 容易写串，建议封装并双哈希校验。"],
  ["Floyd 初始化不完整", "d[i][i]=0，重边取 min，不可达判断用 INF/2。"],
  ["KMP 下标体系混用", "f[i+1] 与 next[i] 写法不同，匹配主串时要按同一套边界。"],
  ["网络流反向边编号错", "addedge 必须成对建边，增广时用 i^1 找反向边。"],
  ["计算几何边界断言写反", "相交/不相交返回值要先统一，eps 比较不能直接用 ==。"],
];

const profiles = {
  "线段树": {
    scenario: "区间加、区间查询、单点修改、动态维护聚合信息。适合题面出现“区间”“修改”“查询”“最值/和”等关键词。",
    core: "把整体区间递归拆成若干线段节点，每个节点保存可合并的信息；懒标记表示对子区间暂缓执行的修改。",
    complexity: "建树 O(n)，单次查询/修改 O(log n)，空间 O(n)。",
    errors: ["`mid = l + r >> 1` 建议写成 `(l + r) >> 1`，避免读代码时误判优先级。", "区间统一使用 `[l, r)` 或 `[l, r]`，不要混用。", "下放懒标记前要保证当前节点确实有标记。"],
    related: ["[[权值线段树]]", "[[主席树]]", "[[线段树分治]]", "[[扫描线]]"],
  },
  "权值线段树": {
    scenario: "维护值域上的频次、排名、第 k 小、动态 multiset。",
    core: "线段树维护的不是下标区间，而是值域区间；节点保存该值域内元素数量或统计信息。",
    complexity: "单次插入/删除/查询 O(log V)，空间 O(操作数 log V) 或 O(V)。",
    errors: ["值域要先离散化或确认上界。", "第 k 小查询时要先判断 k 是否超过总数量。"],
    related: ["[[主席树]]", "[[线段树合并与分裂]]", "[[莫队]]"],
  },
  "主席树": {
    scenario: "静态区间第 k 小、历史版本查询、可持久化频次数组。",
    core: "每次修改只复制根到叶的一条链，其余节点复用；区间查询通过两个前缀版本相减。",
    complexity: "建 n 个版本 O(n log V)，单次查询 O(log V)，空间 O(n log V)。",
    errors: ["离散化后查询答案要映射回原值。", "节点池大小要按 n log n 预估。"],
    related: ["[[权值线段树]]", "[[线段树]]", "[[可撤销并查集]]"],
  },
  "并查集": {
    scenario: "动态合并集合、判断连通性、Kruskal 最小生成树。",
    core: "用父指针表示集合代表元，路径压缩和按大小合并降低树高。",
    complexity: "均摊近似 O(1)，空间 O(n)。",
    errors: ["初始化范围要覆盖所有编号。", "合并前必须 find。", "维护 size 时只能在根节点维护。"],
    related: ["[[可撤销并查集]]", "[[最小生成树]]", "[[线段树分治]]"],
  },
  "可撤销并查集": {
    scenario: "离线动态图连通性、线段树分治、需要回退历史状态的合并问题。",
    core: "不做路径压缩，用栈记录每次成功合并的父子关系和 size 变化，回溯时撤销。",
    complexity: "单次 find/merge O(log n)，回滚按撤销次数计，空间 O(n+m)。",
    errors: ["绝不能路径压缩。", "未成功合并时通常不入栈，时间戳回滚要对应。"],
    related: ["[[并查集]]", "[[线段树分治]]"],
  },
  "线段树分治": {
    scenario: "元素在时间区间内生效，询问在时间点上发生的离线问题。",
    core: "把操作存活区间挂到时间线段树节点，DFS 时间线，用可撤销数据结构维护当前状态。",
    complexity: "每个区间被拆到 O(log q) 个节点，总复杂度 O((操作数 log q) * 数据结构代价)。",
    errors: ["生存区间左右端点要统一 `[l, r)`。", "DFS 返回前必须回滚到进入节点前的时间戳。"],
    related: ["[[可撤销并查集]]", "[[线段树]]"],
  },
  "Dijkstra 算法": {
    scenario: "非负权图单源最短路；稀疏图用堆优化，稠密图可用朴素版。",
    core: "每次取出当前未确定点中距离最小者，该距离即为最终最短路，再用它松弛出边。",
    complexity: "朴素 O(n^2)，堆优化 O((n+m)log n)，空间 O(n+m)。",
    errors: ["不能处理负权边。", "距离建议 long long。", "堆优化要跳过过期状态。"],
    related: ["[[SPFA算法]]", "[[Bellman–Ford 算法]]", "[[Johnson 算法]]"],
  },
  "SPFA算法": {
    scenario: "有负权边的单源最短路、负环判定、差分约束；慎用于强数据。",
    core: "队列维护本轮可能继续松弛其他点的节点，只访问必要边。",
    complexity: "平均表现不稳定，最坏 O(nm)。",
    errors: ["无负权边优先 Dijkstra。", "判负环要记录入队/路径边数。", "vis 表示是否在队列中，不是最短路已确定。"],
    related: ["[[Bellman–Ford 算法]]", "[[差分约束]]", "[[Dijkstra 算法]]"],
  },
  "Bellman–Ford 算法": {
    scenario: "有负权边、限制边数最短路、负环检测。",
    core: "重复对所有边松弛，最多 n-1 轮；第 n 轮仍可松弛说明存在可达负环。",
    complexity: "O(nm)，空间 O(n+m)。",
    errors: ["限制边数版本需要备份上一轮距离。", "不可达点不能参与 INF + w 的有效松弛。"],
    related: ["[[SPFA算法]]", "[[差分约束]]", "[[Johnson 算法]]"],
  },
  "Floyd 算法": {
    scenario: "点数较小的全源最短路、传递闭包、任意两点最短路询问多。",
    core: "枚举中转点 k，逐步允许路径经过更多中转点。",
    complexity: "时间 O(n^3)，空间 O(n^2)。",
    errors: ["三重循环顺序必须 k 在最外层。", "重边取 min，不可达用 INF/2 判断。"],
    related: ["[[Johnson 算法]]", "[[Dijkstra 算法]]"],
  },
  "Johnson 算法": {
    scenario: "稀疏图全源最短路，允许负权边但不能有负环。",
    core: "先用 SPFA/Bellman-Ford 求势能 h，将所有边重标为非负，再对每个源点跑 Dijkstra。",
    complexity: "O(nm) 势能预处理 + O(n(m+n)log n)；稀疏图优于 Floyd。",
    errors: ["最后距离要还原 `dis' - h[s] + h[t]`。", "有负环时必须提前返回无解。"],
    related: ["[[SPFA算法]]", "[[Dijkstra 算法]]", "[[Floyd 算法]]"],
  },
  "差分约束": {
    scenario: "形如 `x_i - x_j <= c` 的不等式系统求可行解/判无解。",
    core: "把约束转化为边 `j -> i` 权值 c，求最短路；负环对应矛盾。",
    complexity: "通常用 SPFA，最坏 O(nm)。",
    errors: ["大于等于约束要先变形成小于等于。", "要加超级源点保证所有变量可达。"],
    related: ["[[SPFA算法]]", "[[Bellman–Ford 算法]]"],
  },
  "最小生成树": {
    scenario: "连通无向图选 n-1 条边使总权最小；也用于瓶颈路、聚类、Kruskal 重构树。",
    core: "Kruskal 按边权排序并用并查集跳过成环边；Prim 从点集扩展。",
    complexity: "Kruskal O(m log m)，Prim 堆优化 O(m log n)。",
    errors: ["图不连通时只有最小生成森林。", "边要按权排序，重边自环要处理。"],
    related: ["[[并查集]]", "[[Kruskal重构树]]"],
  },
  "LCA": {
    scenario: "树上最近公共祖先、树上距离、路径查询、树上差分。",
    core: "倍增或重链剖分把两个点跳到同一深度，再同步上跳。",
    complexity: "预处理 O(n log n)，单次查询 O(log n)，空间 O(n log n)。",
    errors: ["根节点父亲、深度初始化要统一。", "倍增数组越界和 log 上界常出错。"],
    related: ["[[重链剖分]]", "[[树直径]]", "[[点分治]]"],
  },
  "KMP算法": {
    scenario: "单模式串匹配、最小循环节、border 相关问题。",
    core: "失配时利用已知最长相等前后缀跳转，避免主串指针回退。",
    complexity: "预处理 O(m)，匹配 O(n)，空间 O(m)。",
    errors: ["next/f 数组含义和下标要统一。", "模式串为空或长度 1 时注意边界。"],
    related: ["[[扩展kmp（Z函数）]]", "[[AC自动机]]", "[[字符串哈希]]"],
  },
  "字符串哈希": {
    scenario: "快速判断子串相等、去重、回文检测、LCP 二分。",
    core: "把字符串看成 base 进制数，前缀哈希支持 O(1) 取子串哈希。",
    complexity: "预处理 O(n)，查询 O(1)，空间 O(n)。",
    errors: ["base/bs 变量名要一致。", "单哈希可能冲突，关键题建议双哈希或 2^61-1。", "区间 `[l,r)` 长度要写对。"],
    related: ["[[KMP算法]]", "[[Manacher]]", "[[后缀自动机]]", "[[指数哈希]]", "[[异或哈希]]"],
  },
  "AC自动机": {
    scenario: "多模式串匹配、敏感词统计、模式串出现次数。",
    core: "Trie 上补 fail 指针，失配时跳到最长可匹配后缀；统计贡献可沿 fail 树汇总。",
    complexity: "建树 O(模式串总长 * 字符集) 或 O(总长)，匹配 O(文本长)。",
    errors: ["fail 转移要补全，否则匹配时会掉到 0。", "多模式计数要处理重复模式和 fail 树贡献。"],
    related: ["[[Trie树]]", "[[KMP算法]]", "[[后缀自动机]]"],
  },
  "快速傅里叶变换（FFT）": {
    scenario: "实数/复数域卷积、多项式乘法。",
    core: "分治利用单位根把点值表达快速变换，乘法在点值域逐点相乘。",
    complexity: "O(n log n)，空间 O(n)。",
    errors: ["长度要扩到不小于卷积长度的 2 的幂。", "浮点四舍五入和精度误差要处理。"],
    related: ["[[快速数论变换（NTT）]]", "[[普通生成函数]]"],
  },
  "快速数论变换（NTT）": {
    scenario: "模意义下整数卷积、多项式乘法。",
    core: "在有原根的模数下用数论单位根替代复数单位根。",
    complexity: "O(n log n)，空间 O(n)。",
    errors: ["模数必须支持所需长度的原根。", "逆变换后要乘 inv(n)。"],
    related: ["[[快速傅里叶变换（FFT）]]", "[[普通生成函数]]"],
  },
  "计算几何": {
    scenario: "点、向量、直线、线段、圆相关的几何判定和计算。",
    core: "用点积处理投影/夹角，用叉积处理方向/面积/相交，用 eps 统一浮点比较。",
    complexity: "基础操作 O(1)，具体算法视问题而定。",
    errors: ["不要直接比较 double 相等。", "叉积方向和端点接触返回值要先约定。", "断言条件要和函数返回值一致。"],
    related: ["[[扫描线]]", "[[随机]]"],
  },
};

const defaults = {
  scenario(name, cat) {
    if (cat === "图论") return `图结构上的 ${name} 模板，适合出现路径、连通性、树、匹配、网络流等关键词时检索。`;
    if (cat === "动态规划") return `DP 状态转移类问题，适合从“选择/阶段/容量/最优值”角度建模。`;
    if (cat === "字符串") return `字符串匹配、统计、自动机或子串结构问题。`;
    if (cat === "数论") return `数值、组合、多项式、模运算或代数结构相关题目。`;
    if (cat === "数据结构") return `需要维护动态信息、支持查询/修改/合并/回滚的数据结构题。`;
    if (cat === "杂项工具") return `比赛中辅助建模、优化实现或降低出错率的工具模板。`;
    return `${name} 相关竞赛场景。`;
  },
  core(name) {
    return `${name} 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。`;
  },
  complexity: "见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。",
  errors: ["确认下标从 0 还是 1 开始。", "确认数组大小、INF、取模和 long long。", "提交前用最小样例、边界样例和随机数据各测一次。"],
};

function walk(dir) {
  const ans = [];
  for (const entry of fs.readdirSync(dir, { withFileTypes: true })) {
    if (entry.isDirectory()) {
      if (!skipDirs.has(entry.name)) ans.push(...walk(path.join(dir, entry.name)));
    } else if (entry.name.endsWith(".md") && !skipNames.has(entry.name)) {
      ans.push(path.join(dir, entry.name));
    }
  }
  return ans;
}

function rel(p) {
  return path.relative(root, p).replaceAll("\\", "/");
}

function ensureDir(p) {
  fs.mkdirSync(p, { recursive: true });
}

function cleanTitle(file) {
  return path.basename(file, ".md");
}

function inferCategory(relative, title) {
  const top = relative.split("/")[0];
  if (top === "数据结构") return "数据结构";
  if (top === "图论") return "图论";
  if (top === "动态规划") return "动态规划";
  if (top === "字符串") return "字符串";
  if (top === "数论") return "数论";
  if (top === "杂项") {
    if (title.includes("哈希")) return title === "字符串哈希" ? "字符串" : "杂项工具";
    if (title.includes("扫描线")) return "数据结构";
    return "杂项工具";
  }
  if (title.includes("计算几何")) return "计算几何";
  if (title.includes("题单")) return "题单与索引";
  if (top === "templates") return "知识库维护";
  return "杂项工具";
}

function wikiName(title) {
  const map = {
    "SPFA算法": "SPFA算法",
    "KMP算法": "KMP算法",
    "扩展kmp（Z函数）": "扩展kmp（Z函数）",
  };
  return map[title] || title;
}

function tagForCategory(cat) {
  return {
    "数据结构": "ds",
    "图论": "graph",
    "动态规划": "dp",
    "字符串": "string",
    "数论": "math",
    "计算几何": "geometry",
    "杂项工具": "tool",
    "题单与索引": "problemset",
    "知识库维护": "wiki",
  }[cat] || "acm";
}

function profileFor(title, cat) {
  const key = Object.keys(profiles).find((k) => title === k || title.includes(k) || k.includes(title));
  if (key) return profiles[key];
  return {
    scenario: defaults.scenario(title, cat),
    core: defaults.core(title),
    complexity: defaults.complexity,
    errors: defaults.errors,
    related: inferRelated(title, cat),
  };
}

function inferRelated(title, cat) {
  const byCat = {
    "数据结构": ["[[线段树]]", "[[并查集]]", "[[莫队]]"],
    "图论": ["[[Dijkstra 算法]]", "[[LCA]]", "[[最小生成树]]"],
    "动态规划": ["[[01背包问题]]", "[[完全背包问题]]", "[[多重背包问题的二进制优化]]"],
    "字符串": ["[[KMP算法]]", "[[字符串哈希]]", "[[Trie树]]"],
    "数论": ["[[矩阵快速幂]]", "[[快速数论变换（NTT）]]", "[[线性基]]"],
    "计算几何": ["[[扫描线]]"],
    "杂项工具": ["[[ACM综合模板]]", "[[随机]]"],
  };
  return (byCat[cat] || ["[[ACM知识库总览]]"]).filter((x) => !x.includes(title));
}

function stripFrontmatter(s) {
  return s.replace(/^---\r?\n[\s\S]*?\r?\n---\r?\n/, "").trim();
}

function balanceFences(s) {
  const count = (s.match(/```/g) || []).length;
  return count % 2 === 0 ? s : `${s.trimEnd()}\n\`\`\``;
}

function firstHeadingOrTitle(content, title) {
  const m = content.match(/^#\s+(.+)$/m);
  return m ? m[1].trim() : title;
}

function cardMarkdown(card) {
  const p = profileFor(card.title, card.category);
  const related = (p.related || inferRelated(card.title, card.category)).join("\n");
  const err = (p.errors || defaults.errors).map((x) => `- ${x}`).join("\n");
  const sourceList = card.sources.map((s) => `- ${s}`).join("\n");
  const sourceYaml = card.sources.map((s) => `  - "${s}"`).join("\n");
  const sourceContent = card.sources
    .map((s, i) => `### ${i === 0 ? "标准版（推荐）" : i === 1 ? "扩展版（进阶）" : "竞赛特化版（极限优化）"}\n\n> 来源：${s}\n\n${balanceFences(card.contents[i])}`)
    .join("\n\n---\n\n");

  return `---\ntags:\n  - acm\n  - ${tagForCategory(card.category)}\ncategory: ${card.category}\nsource:\n${sourceYaml}\n---\n\n# ${card.title}\n\n## 模块名称\n\n${card.title}\n\n## 来源\n\n${sourceList}\n\n## 适用场景\n\n${p.scenario || defaults.scenario(card.title, card.category)}\n\n## 核心思想\n\n${p.core || defaults.core(card.title)}\n\n## 标准代码模板\n\n${sourceContent}\n\n## 复杂度\n\n${p.complexity || defaults.complexity}\n\n## 常见错误\n\n${err}\n\n## 相关联知识\n\n${related}\n`;
}

function mocMarkdown(cat, cards) {
  const rows = cards.map((c) => `- [[${c.title}]]`).join("\n");
  return `---\ntags:\n  - acm\n  - moc\n  - ${tagForCategory(cat)}\n---\n\n# ${cat}\n\n## 知识卡片\n\n${rows}\n\n## 本类复习提示\n\n- 先掌握本类的标准版模板，再补扩展版。\n- 每张卡片都保留了原始来源，方便回看旧笔记。\n- 复习时优先看“适用场景”和“常见错误”，比赛前再看代码。\n`;
}

function writeFile(p, content) {
  ensureDir(path.dirname(p));
  fs.writeFileSync(p, content.replace(/\r\n/g, "\n"), "utf8");
}

function build() {
  fs.rmSync(outRoot, { recursive: true, force: true });
  ensureDir(outRoot);

  const files = walk(root);
  const groups = new Map();

  for (const file of files) {
    const relative = rel(file);
    const title0 = cleanTitle(file);
    if (title0 === "ACM模板") {
      const title = "ACM综合模板";
      const key = title;
      const content = stripFrontmatter(fs.readFileSync(file, "utf8"));
      groups.set(key, { title, category: "杂项工具", sources: [relative], contents: [content] });
      continue;
    }
    const contentRaw = fs.readFileSync(file, "utf8");
    if (!contentRaw.trim()) continue;
    const title = firstHeadingOrTitle(stripFrontmatter(contentRaw), title0).replace(/^Johnson 全源最短路径算法$/, "Johnson 算法");
    const normalized = title === "String Hash" ? "字符串哈希" : wikiName(title0);
    const category = inferCategory(relative, normalized);
    const key = normalized;
    const content = stripFrontmatter(contentRaw);
    if (!groups.has(key)) groups.set(key, { title: normalized, category, sources: [], contents: [] });
    const g = groups.get(key);
    if (g.category === "杂项工具" && category !== "杂项工具") g.category = category;
    g.sources.push(relative);
    g.contents.push(content);
  }

  const cards = [...groups.values()].sort((a, b) => {
    const ca = categoryOrder.indexOf(a.category);
    const cb = categoryOrder.indexOf(b.category);
    return (ca - cb) || a.title.localeCompare(b.title, "zh-CN");
  });

  for (const cat of categoryOrder.slice(1)) ensureDir(path.join(outRoot, cat));
  for (const card of cards) {
    writeFile(path.join(outRoot, card.category, `${card.title}.md`), cardMarkdown(card));
  }

  const byCat = new Map();
  for (const card of cards) {
    if (!byCat.has(card.category)) byCat.set(card.category, []);
    byCat.get(card.category).push(card);
  }
  for (const [cat, cs] of byCat) {
    writeFile(path.join(outRoot, `${cat}.md`), mocMarkdown(cat, cs));
  }

  const tree = categoryOrder
    .slice(1)
    .filter((cat) => byCat.has(cat))
    .map((cat) => `├── ${cat}\n${byCat.get(cat).map((c, i, arr) => `${i === arr.length - 1 ? "│   └──" : "│   ├──"} [[${c.title}]]`).join("\n")}`)
    .join("\n");

  const topMd = top15.map((x, i) => `${i + 1}. [[${x[0]}]]：${x[1]}`).join("\n");
  const wrongMd = commonWrong.map((x, i) => `${i + 1}. ${x[0]}：${x[1]}`).join("\n");

  const overview = `---\ntags:\n  - acm\n  - wiki\n  - moc\n---\n\n# ACM知识库总览\n\n## 总知识目录\n\n\`\`\`text\nACM知识库\n${tree}\n\`\`\`\n\n## 分类入口\n\n${[...byCat.keys()].map((cat) => `- [[${cat}]]`).join("\n")}\n\n## 高频模板 TOP 15\n\n${topMd}\n\n## 易错知识 TOP 10\n\n${wrongMd}\n\n## 学习路径建议\n\n### 初学顺序\n\n1. [[并查集]]、[[线段树]]、[[01背包问题]]、[[完全背包问题]]\n2. [[Dijkstra 算法]]、[[最小生成树]]、[[LCA]]\n3. [[KMP算法]]、[[字符串哈希]]、[[Trie树]]\n4. [[矩阵快速幂]]、[[线性基]]、[[快速傅里叶变换（FFT）]]\n\n### 提升顺序\n\n1. 数据结构进阶：[[主席树]]、[[权值线段树]]、[[线段树分治]]、[[莫队]]\n2. 图论进阶：[[强连通分量]]、[[点双连通分量]]、[[Dinic]]、[[费用流]]\n3. 字符串进阶：[[AC自动机]]、[[后缀自动机]]、[[Manacher]]\n4. 数学进阶：[[快速数论变换（NTT）]]、[[普通生成函数]]、[[二项式反演]]\n\n### 比赛前速刷顺序\n\n1. 先看 [[ACM综合模板]]、[[线段树]]、[[并查集]]、[[Dijkstra 算法]]、[[LCA]]。\n2. 再看 [[字符串哈希]]、[[KMP算法]]、[[Dinic]]、[[费用流]]、[[计算几何]]。\n3. 最后扫一遍本页“易错知识 TOP 10”，把 long long、INF、数组范围、下标体系检查完。\n\n## Obsidian 知识图谱\n\n\`\`\`mermaid\ngraph TD\n  A[ACM知识库] --> DS[数据结构]\n  A --> G[图论]\n  A --> DP[动态规划]\n  A --> S[字符串]\n  A --> M[数论]\n  A --> GEO[计算几何]\n  A --> T[杂项工具]\n  DS --> Seg[线段树]\n  DS --> Dsu[并查集]\n  G --> Dij[Dijkstra]\n  G --> Flow[网络流]\n  DP --> Bag[背包DP]\n  S --> KMP[KMP]\n  S --> Hash[字符串哈希]\n  M --> NTT[NTT/FFT]\n  GEO --> Cross[叉积/点积]\n\`\`\`\n`;
  writeFile(path.join(outRoot, "00 ACM知识库总览.md"), overview);

  const topFile = `# 高频模板 TOP 15\n\n${topMd}\n\n## 上场必带代码\n\n- [[ACM综合模板]]\n- [[线段树]]\n- [[并查集]]\n- [[Dijkstra 算法]]\n- [[Dinic]]\n- [[费用流]]\n- [[字符串哈希]]\n- [[KMP算法]]\n- [[计算几何]]\n\n## 10分钟内能写错的点\n\n${wrongMd}\n`;
  writeFile(path.join(outRoot, "01 高频模板 TOP 15.md"), topFile);

  const routeFile = `# 学习路径建议\n\n## 初学顺序\n\n1. 基础语法与 [[ACM综合模板]]\n2. [[并查集]]、[[线段树]]、[[01背包问题]]、[[完全背包问题]]\n3. [[Dijkstra 算法]]、[[最小生成树]]、[[LCA]]\n4. [[KMP算法]]、[[字符串哈希]]、[[Trie树]]\n\n## 提升顺序\n\n1. [[主席树]]、[[权值线段树]]、[[线段树分治]]\n2. [[强连通分量]]、[[点双连通分量]]、[[Dinic]]、[[费用流]]\n3. [[AC自动机]]、[[后缀自动机]]、[[Manacher]]\n4. [[快速傅里叶变换（FFT）]]、[[快速数论变换（NTT）]]、[[普通生成函数]]\n\n## 比赛前速刷顺序\n\n1. 图论：[[Dijkstra 算法]]、[[SPFA算法]]、[[最小生成树]]、[[LCA]]、[[Dinic]]\n2. 数据结构：[[线段树]]、[[并查集]]、[[主席树]]、[[莫队]]\n3. 字符串：[[KMP算法]]、[[字符串哈希]]、[[AC自动机]]\n4. 数学与工具：[[矩阵快速幂]]、[[快速数论变换（NTT）]]、[[int128类定义]]、[[随机]]\n`;
  writeFile(path.join(outRoot, "02 学习路径建议.md"), routeFile);

  console.log(`Generated ${cards.length} cards in ${outRoot}`);
}

build();
