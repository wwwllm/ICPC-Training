# check.py —— 简单的答案校验脚本（本地对拍用）：check.py <输入文件> <输出文件>
# 校验规则与 SPJ 一致：输出必须是 Q 个整数；非 -1 的答案必须真的满足 cnt*q > len*p。
import sys
def main():
    inp, out = open(sys.argv[1]), open(sys.argv[2])
    n, Q = map(int, inp.readline().split())
    a = list(map(int, inp.readline().split()))
    assert len(a) == n, "数组长度不符"
    pos = {}
    for i, v in enumerate(a, 1):
        pos.setdefault(v, []).append(i)
    import bisect
    toks = out.read().split()
    if len(toks) != Q:
        print("PE: 输出 %d 个整数, 期望 %d" % (len(toks), Q)); sys.exit(1)
    for qi in range(Q):
        l, r, p, q = map(int, inp.readline().split())
        x = int(toks[qi])
        if x == -1:
            continue
        ps = pos.get(x)
        if not ps:
            print("WA: 第 %d 个询问输出了不存在的数 %d" % (qi + 1, x)); sys.exit(1)
        c = bisect.bisect_right(ps, r) - bisect.bisect_left(ps, l)
        if c * q <= (r - l + 1) * p:
            print("WA: 第 %d 个询问输出 %d, 出现 %d 次, 不满足 %d/%d" % (qi + 1, x, c, p, q)); sys.exit(1)
    print("OK")
main()
