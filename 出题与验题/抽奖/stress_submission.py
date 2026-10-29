#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
stress_submission.py —— 把一份提交反复跑在全部数据点上，统计 WA 率与耗时。
用法: python stress_submission.py submissions/sol_M100.cpp [轮数]

每个测试点跑 N 轮（默认 20），用独立校验器 checker1 判题，
输出「WA 轮数 / 总轮数」和单轮最大耗时。
"""
import os, subprocess, sys, time

ROOT = os.path.dirname(os.path.abspath(__file__))
BIN = os.path.join(ROOT, "bin")
EXE = ".exe" if os.name == "nt" else ""


def B(n):
    return os.path.join(BIN, n + EXE)


def list_dat(d):
    return sorted([f for f in os.listdir(d) if f.endswith(".in")],
                  key=lambda s: int("".join(c for c in s if c.isdigit())))


def main():
    src = os.path.join(ROOT, sys.argv[1])
    rounds = int(sys.argv[2]) if len(sys.argv) > 2 else 20
    exe = B("submit")
    r = subprocess.run('g++ -O2 -std=c++20 -o "%s" "%s"' % (exe, src), shell=True,
                       cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    if r.returncode != 0:
        print(r.stdout.decode("utf-8", "ignore"))
        raise SystemExit("编译失败")
    print("编译完成: %s   （每个数据点跑 %d 轮）\n" % (sys.argv[1], rounds))
    d = os.path.join(ROOT, "1")
    print("%-8s %-6s %-10s %-9s %s" % ("数据点", "Q", "WA 轮数", "最慢耗时", "失败原因举例"))
    for f in list_dat(d):
        inp = os.path.join(d, f)
        out = inp[:-3] + ".out"
        Q = sum(1 for _ in open(out))
        wa = 0
        worst = 0.0
        msg = ""
        for _ in range(rounds):
            t0 = time.time()
            with open(inp, "rb") as fi, open(B("submit.out"), "wb") as fo:
                subprocess.run([exe], stdin=fi, stdout=fo)
            el = time.time() - t0
            worst = max(worst, el)
            chk = subprocess.run([B("checker1"), inp, B("submit.out")],
                                 stdout=subprocess.PIPE)
            m = chk.stdout.decode("utf-8", "ignore").strip()
            if m != "ok":
                wa += 1
                if not msg:
                    msg = m[:60]
        print("%-8s %-6d %-10s %-9s %s" % (f, Q, "%d/%d" % (wa, rounds),
                                           "%.2fs" % worst, msg))


main()
