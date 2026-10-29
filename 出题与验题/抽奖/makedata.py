#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
makedata.py —— 一键编译 + 生成 + 校验两题的测试数据。

    python makedata.py            # 全部（编译 / 造数据 / 跑 std / 校验）
    python makedata.py build      # 只编译
    python makedata.py gen        # 只造数据
    python makedata.py run        # 只跑 std 生成 .out
    python makedata.py check      # 只校验

目录约定:
    1/datN.in  1/datN.out        第一题（抽奖，随机化）
    2/datN.in  2/datN.out        第二题（最后的数，guess）
    bin/                         编译产物
"""
import os, subprocess, sys, time, random

ROOT = os.path.dirname(os.path.abspath(__file__))
BIN = os.path.join(ROOT, "bin")
EXE = ".exe" if os.name == "nt" else ""


def run(cmd, stdin=None, stdout=subprocess.PIPE, timeout=900):
    return subprocess.run(cmd, shell=isinstance(cmd, str), cwd=ROOT, stdin=stdin,
                          stdout=stdout, stderr=subprocess.STDOUT, timeout=timeout)


def B(name):
    return os.path.join(BIN, name + EXE)


# ============================== 编译 ==============================
SRCS = ["std1", "std1_det", "checker1", "brute1", "gen1", "std2", "brute2", "gen2"]


def build():
    os.makedirs(BIN, exist_ok=True)
    for s in SRCS:
        t0 = time.time()
        r = run('g++ -O2 -static -o "%s" "%s.cpp"' % (B(s), s))
        if r.returncode != 0:
            print(r.stdout.decode("utf-8", "ignore"))
            raise SystemExit("编译 %s 失败" % s)
        print("  编译 %-9s %.1fs" % (s, time.time() - t0))


# ============================== 第一题 ==============================
# (编号, 生成命令(gen1 后面的参数), 说明)
GEN1 = [
    (2,  "1 101 1 5 1",                     "n=1，全是单点询问"),
    (3,  "1 102 30 30 5",                   "小数据随机（值域 5）"),
    (4,  "1 103 500 500 3",                 "中数据随机（值域 3，答案很多）"),
    (5,  "1 104 2000 2000 11",              "值域 11：出现频率贴近 1/10，答案很少"),
    (6,  "2 105 2000 2000",                 "所有数互不相同 → 全是 -1"),
    (7,  "5 106 1 10 20000 1500",           "恰好卡在阈值 1/10 上 → 必须全 -1（杀 >= 假做法）"),
    (8,  "5 107 1 4 20000 800",             "恰好卡在阈值 1/4 上 → 必须全 -1"),
    (9,  "4 108 1 10 20000 1500",           "每段唯一答案，出现次数 = floor(len/10)+1（刚好超过阈值）"),
    (10, "4 109 1 3 20000 600",             "阈值 1/3 的唯一答案数据"),
    (11, "3 110 100000 100000 11 110 100000", "循环 11 个值 + 长区间 → 全是 -1（n=Q=1e5）"),
    (12, "2 111 100000 100000",             "n=Q=1e5，所有数互不相同 → 全是 -1"),
    (13, "6 112 100000 100000 300 2000",    "对抗性：300 个值循环 + 长度 2000 的区间（随机化做法最慢的一类）"),
    (14, "7 113 100000 100000",             "询问全是 [1,n]"),
    (15, "8 114 100000 100000",             "询问全是单点 [i,i]"),
    (16, "9 115 1 10 100000 100000",        "每个区间唯一答案（占比约 1/10），必须全部命中"),
    (17, "1 116 100000 100000 9",           "n=Q=1e5，值域 9：频率约 11%，答案多且贴近阈值"),
    (18, "1 117 100000 100000 3",           "n=Q=1e5，值域 3：答案很多"),
    (20, "6 119 100000 100000 11 200",      "11 个值循环 + 长度 200 的区间（短区间 + 多值混合）"),
]

SAMPLE1 = "5 4\n1 2 1 2 1\n1 5 1 2\n1 5 1 10\n2 5 1 10\n1 1 1 2\n"


def mk1_dat19(n=100000, Q=100000):
    """所有数都等于 7 → 每个询问的答案都是 7（阈值故意取到 9/10）"""
    random.seed(19)
    out = ["%d %d" % (n, Q), " ".join(["7"] * n)]
    fr = [(1, 10), (1, 2), (9, 10), (1, 3), (1, 9), (999, 1000)]
    for _ in range(Q):
        l = random.randint(1, n)
        r = random.randint(l, n)
        out.append("%d %d %d %d" % (l, r, *random.choice(fr)))
    return "\n".join(out) + "\n"


def mk1_dat21(n=100000, Q=100000):
    """p、q 都是接近 1e9 的大数（验证 64 位乘法不溢出）"""
    random.seed(21)
    V = 10
    out = ["%d %d" % (n, Q), " ".join(str(i % V + 1) for i in range(n))]
    fr = [(100000000, 1000000000), (100000001, 1000000000),
          (100000000, 999999999), (123456789, 999999937)]
    for _ in range(Q):
        l = random.randint(1, n)
        r = random.randint(l, n)
        out.append("%d %d %d %d" % (l, r, *random.choice(fr)))
    return "\n".join(out) + "\n"


def gen1_data():
    d = os.path.join(ROOT, "1")
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "dat1.in"), "w") as f:
        f.write(SAMPLE1)
    print("  1/dat1   题面样例")
    for no, args, desc in GEN1:
        with open(os.path.join(d, "dat%d.in" % no), "wb") as f:
            r = run([B("gen1")] + args.split(), stdout=f)
        if r.returncode != 0:
            raise SystemExit("生成 dat%d 失败" % no)
        print("  1/dat%-4d %s" % (no, desc))
    with open(os.path.join(d, "dat19.in"), "w") as f:
        f.write(mk1_dat19())
    print("  1/dat19   所有数都等于 7，每个询问的答案都是 7（含阈值 9/10）")
    with open(os.path.join(d, "dat21.in"), "w") as f:
        f.write(mk1_dat21())
    print("  1/dat21   p、q 接近 1e9 的大数（验证 64 位乘法）")


def list_dir(d):
    return sorted([f for f in os.listdir(d) if f.endswith(".in")],
                  key=lambda s: int("".join(c for c in s if c.isdigit())))


def run1():
    d = os.path.join(ROOT, "1")
    for f in list_dir(d):
        inp = os.path.join(d, f)
        t0 = time.time()
        with open(inp[:-3] + ".out", "wb") as fo, open(inp, "rb") as fi:
            run([B("std1")], stdin=fi, stdout=fo)
        nlines = sum(1 for _ in open(inp[:-3] + ".out"))
        print("  1/%-10s .out  %.2fs  共 %d 行" % (f, time.time() - t0, nlines))


def check1():
    d = os.path.join(ROOT, "1")
    allok = True
    for f in list_dir(d):
        inp = os.path.join(d, f)
        out = inp[:-3] + ".out"
        r = run([B("checker1"), inp, out])
        msg = r.stdout.decode("utf-8", "ignore").strip()
        # 独立验证 1：与确定性做法（线段树摘要）比较「有解/无解」
        det = subprocess.run([B("std1_det")], stdin=open(inp, "rb"), stdout=subprocess.PIPE)
        a = open(out).read().split()
        b = det.stdout.decode().split()
        diff = [i for i in range(min(len(a), len(b))) if (a[i] == "-1") != (b[i] == "-1")]
        detmsg = "确定性做法一致" if (not diff and len(a) == len(b)) else "!!确定性做法不一致 %s" % diff[:3]
        # 独立验证 2：小数据用暴力精确对拍
        first = open(inp).readline().split()
        n, Q = int(first[0]), int(first[1])
        bru = "-"
        if n <= 20000 and Q <= 5000:
            rb = subprocess.run([B("brute1")], stdin=open(inp, "rb"), stdout=subprocess.PIPE)
            c = rb.stdout.decode().split()
            bad = [i for i in range(min(len(a), len(c))) if (a[i] == "-1") != (c[i] == "-1")]
            bru = "暴力对拍一致" if (not bad and len(a) == len(c)) else "!!暴力对拍不一致 %s" % bad[:3]
        n1 = a.count("-1")
        good = (msg == "ok" and "!!" not in detmsg and "!!" not in bru)
        allok = allok and good
        print("  %-10s SPJ=%-4s %-12s %-12s  (Q=%d, -1 有 %d 个)" %
              (f, msg, detmsg, bru, Q, n1))
    print("  => 第一题：%s" % ("全部通过" if allok else "存在问题！"))
    return allok


# ============================== 第二题 ==============================
GEN2 = [
    (2,  "5 201",                          "n = 1..12 的所有 k 穷举（暴力可精确对拍）"),
    (3,  "1 202 3000 60",                  "小数据随机 n<=60"),
    (4,  "6 203 100000 1000000000",        "k 全在 n 附近（卡结论边界），t=1e5"),
    (5,  "4 204 100000",                   "n ≡ 0,1,2,3 (mod 4)，k ∈ {0,1,2,n-2,n-1,n,n+1,n+2}"),
    (6,  "2 205 100000 1",                 "固定 n=1"),
    (7,  "2 206 100000 2",                 "固定 n=2"),
    (8,  "2 207 100000 4",                 "固定 n=4"),
    (9,  "2 208 100000 1000000000",        "固定最大 n=1e9（n ≡ 0 mod 4）"),
    (10, "3 209 100000",                   "n,k ∈ [1,1e9] 随机，t=1e5"),
    (11, "1 210 100000 1000000000",         "n 可达 1e9 的随机数据（含大量 k > n）"),
    (12, "2 211 100000 999999999",         "固定 n=999999999（n ≡ 3 mod 4）"),
]

SAMPLE2 = "5\n3 2\n3 1\n2 1\n4 4\n6 6\n"


def gen2_data():
    d = os.path.join(ROOT, "2")
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "dat1.in"), "w") as f:
        f.write(SAMPLE2)
    print("  2/dat1   题面样例")
    for no, args, desc in GEN2:
        with open(os.path.join(d, "dat%d.in" % no), "wb") as f:
            r = run([B("gen2")] + args.split(), stdout=f)
        if r.returncode != 0:
            raise SystemExit("生成 dat%d 失败" % no)
        print("  2/dat%-4d %s" % (no, desc))


def run2_and_check():
    d = os.path.join(ROOT, "2")
    allok = True
    for f in list_dir(d):
        inp = os.path.join(d, f)
        out = inp[:-3] + ".out"
        t0 = time.time()
        with open(out, "wb") as fo, open(inp, "rb") as fi:
            run([B("std2")], stdin=fi, stdout=fo)
        el = time.time() - t0
        lines = open(inp).read().splitlines()
        ns = [int(x.split()[0]) for x in lines[1:] if x.strip()]
        ks = [int(x.split()[1]) for x in lines[1:] if x.strip()]
        # 数据范围检查：1 <= n <= 1e9, 0 <= k <= 1e9
        bad = [i for i in range(len(ns)) if not (1 <= ns[i] <= 10**9) or not (0 <= ks[i] <= 10**9)]
        bound = "范围check: n<=1e9,k<=1e9 通过(最大 n=%s)" % (max(ns) if ns else 0)
        if bad:
            bound = "!!范围越界 %s" % bad[:3]
            allok = False
        notes = [bound]
        if ns and max(ns) <= 12:
            rb = subprocess.run([B("brute2")], stdin=open(inp, "rb"), stdout=subprocess.PIPE)
            same = rb.stdout.decode().split() == open(out).read().split()
            notes.append("暴力对拍一致" if same else "!!暴力对拍不一致")
            allok = allok and same
        # 题面样例固定答案检查
        if f == "dat1.in":
            expect = ["Yes", "No", "Yes", "Yes", "No"]
            got = open(out).read().split()
            notes.append(("样例答案 %s" % got) + ("" if got == expect else "  !!与题面不符"))
            allok = allok and got == expect
        print("  2/%-10s .out  %.2fs  %s" % (f, el, " | ".join(notes)))
    print("  => 第二题：%s" % ("全部通过" if allok else "存在问题！"))
    return allok


def pack_spj():
    """把 spj1_testlib.cpp 原样复制为 1/chk.cc（OJ 要求的扩展名），保证两边永远一致"""
    src = os.path.join(ROOT, "spj1_testlib.cpp")
    dst = os.path.join(ROOT, "1", "chk.cc")
    with open(src, "rb") as fi, open(dst, "wb") as fo:
        fo.write(fi.read())
    print("  1/chk.cc  <-  spj1_testlib.cpp (%d 字节)" % os.path.getsize(dst))


def check_config():
    """检查两个 config.yaml：测试点是否齐全、题面分数是否为 100、检查器是否存在"""
    import re
    allok = True
    for prob, need_checker in (("1", True), ("2", False)):
        d = os.path.join(ROOT, prob)
        cfg = os.path.join(d, "config.yaml")
        if not os.path.exists(cfg):
            print("  !!缺少 %s/config.yaml" % prob)
            allok = False
            continue
        text = open(cfg, encoding="utf-8").read()
        ins = re.findall(r"^\s*-?\s*input:\s*(\S+)", text, re.M)
        outs = re.findall(r"^\s*-?\s*output:\s*(\S+)", text, re.M)
        scores = [int(x) for x in re.findall(r"^\s*-?\s*score:\s*(\d+)", text, re.M)]
        real = set(list_dir(d))
        missing = [f for f in ins + outs if not os.path.exists(os.path.join(d, f))]
        unused = sorted(real - set(ins), key=lambda s: int("".join(c for c in s if c.isdigit())))
        problems = []
        if missing:
            problems.append("配置里列了但文件不存在: %s" % missing)
        if unused:
            problems.append("数据里有但配置没用到: %s" % unused)
        if sum(scores) != 100:
            problems.append("分数合计 = %s（应为 100）" % sum(scores))
        if len(ins) != len(outs) or len(ins) != len([f for f in real]):
            problems.append("input/output 条数 %d/%d 与数据点 %d 不匹配" % (len(ins), len(outs), len(real)))
        if need_checker:
            chk = re.search(r"^checker:\s*(\S+)", text, re.M)
            if not chk:
                problems.append("没有配置 checker（本题需要 SPJ）")
            elif not os.path.exists(os.path.join(d, chk.group(1))):
                problems.append("checker 文件 %s 不存在" % chk.group(1))
        allok = allok and not problems
        print("  %s/config.yaml：%d 个测试点，分数 %s%s" %
              (prob, len(ins), "+".join(map(str, scores)), "" if not problems else "  !!" + "；".join(problems)))
    print("  => 配置与数据一致性：%s" % ("通过" if allok else "存在问题！"))
    return allok


def check_spj_testlib():
    """编译并试用打包用的 testlib 检查器 1/chk.cc（正例必须 ok，反例必须 WA）"""
    src = os.path.join(ROOT, "1", "chk.cc")
    if not os.path.exists(src):
        print("  (跳过：1/chk.cc 不存在)")
        return True
    if not os.path.exists(os.path.join(ROOT, "testlib.h")):
        print("  (跳过：目录下没有 testlib.h)")
        return True
    r = run('g++ -O2 -std=c++17 -I. -o "%s" 1/chk.cc' % B("chk"))
    if r.returncode != 0:
        print(r.stdout.decode("utf-8", "ignore"))
        print("  !!1/chk.cc 编译失败")
        return False
    ok = True
    for name in ("dat1", "dat9", "dat13", "dat19", "dat21"):
        inp = os.path.join(ROOT, "1", name + ".in")
        out = inp[:-3] + ".out"
        m = run([B("chk"), inp, out, out]).stdout.decode("utf-8", "ignore").strip()
        # 负例：把答案全改成 -1（原本就是 -1 的改成 1），必须被判 WA
        a = open(out).read().split()
        neg = os.path.join(BIN, "neg.out")
        with open(neg, "w") as f:
            f.write("\n".join(("1" if t == "-1" else "-1") for t in a) + "\n")
        m2 = run([B("chk"), inp, neg, out]).stdout.decode("utf-8", "ignore").strip()
        good = m.startswith("ok") and m2.startswith("wrong answer")
        ok = ok and good
        print("  %-6s 正例: %-28s 反例: %s" % (name, m[:28], m2[:34]))
    print("  => 1/chk.cc（SPJ）：%s" % ("通过" if ok else "存在问题！"))
    return ok


if __name__ == "__main__":
    what = sys.argv[1] if len(sys.argv) > 1 else "all"
    if what in ("all", "build"):
        print("[编译]"); build()
    if what in ("all", "gen"):
        print("[生成第一题数据]"); gen1_data()
        print("[生成第二题数据]"); gen2_data()
        print("[打包 SPJ 到数据文件夹]"); pack_spj()
    if what in ("all", "run"):
        print("[跑第一题 std 生成 .out]"); run1()
    if what in ("all", "check"):
        print("[校验第一题]"); check1()
        print("[校验 1/chk.cc（SPJ）]"); check_spj_testlib()
        print("[校验配置文件]"); check_config()
        print("[跑第二题 std 并校验]"); run2_and_check()
    print("完成。")
