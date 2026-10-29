# cmp1.py —— 对拍脚本：cmp1.py <输入> <std输出> <暴力输出>
# 暴力是精确的，因此要求：
#   1) 两者同时判定「有答案 / 无答案」；
#   2) std 输出的答案必须真的满足 cnt*q > len*p。
import sys, bisect

def load(inp_path):
    f = open(inp_path)
    n, Q = map(int, f.readline().split())
    a = list(map(int, f.readline().split()))
    qs = [tuple(map(int, f.readline().split())) for _ in range(Q)]
    return n, Q, a, qs, f

def main():
    inp, sa, sb = sys.argv[1], sys.argv[2], sys.argv[3]
    n, Q, a, qs, _ = load(inp)
    A = open(sa).read().split()
    B = open(sb).read().split()
    if len(A) != Q or len(B) != Q:
        print("FAIL 行数不符 std=%d brute=%d Q=%d" % (len(A), len(B), Q)); sys.exit(1)
    pos = {}
    for i, v in enumerate(a, 1):
        pos.setdefault(v, []).append(i)
    bad = 0
    for i, (l, r, p, q) in enumerate(qs):
        x, y = int(A[i]), int(B[i])
        if (x == -1) != (y == -1):
            print("FAIL 第%d个询问判定不一致: std=%d brute=%d  (l=%d r=%d p=%d q=%d)" % (i + 1, x, y, l, r, p, q))
            bad += 1
        if x != -1:
            ps = pos.get(x, [])
            c = bisect.bisect_right(ps, r) - bisect.bisect_left(ps, l)
            if c * q <= (r - l + 1) * p:
                print("FAIL 第%d个询问答案无效: %d cnt=%d (l=%d r=%d p=%d q=%d)" % (i + 1, x, c, l, r, p, q))
                bad += 1
        if bad >= 5:
            break
    print("FAIL" if bad else "OK")
    sys.exit(1 if bad else 0)

main()
