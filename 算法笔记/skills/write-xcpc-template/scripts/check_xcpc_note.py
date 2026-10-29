#!/usr/bin/env python3
"""Validate the structure of an XCPC Markdown note or Codebook page."""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path


NOTE_INTRO = {"定义", "功能", "介绍"}
NOTE_IMPLEMENTATION = re.compile(r"实现|做法|算法流程")
PLACEHOLDER = re.compile(
    r"<(?:算法名|一级类别|二级类别|YYYY-MM-DD|用途[^>]*|核心[^>]*|"
    r"可复用[^>]*|可靠链接[^>]*)>|\bTODO\b|待补充",
    re.IGNORECASE,
)


def headings(text: str) -> list[tuple[int, str]]:
    return [
        (len(match.group(1)), match.group(2).strip())
        for match in re.finditer(r"(?m)^(#{1,6})\s+(.+?)\s*$", text)
    ]


def code_blocks(text: str, language: str = "cpp") -> list[str]:
    pattern = rf"(?ms)^```{re.escape(language)}\s*\n(.*?)^```\s*$"
    return [match.group(1) for match in re.finditer(pattern, text)]


def validate(path: Path, mode: str) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    warnings: list[str] = []

    try:
        text = path.read_text(encoding="utf-8-sig")
    except (OSError, UnicodeError) as exc:
        return [f"无法按 UTF-8 读取文件：{exc}"], warnings

    hs = headings(text)
    names = [name for _, name in hs]
    fences = re.findall(r"(?m)^```.*$", text)
    cpp = code_blocks(text)

    if len(fences) % 2:
        errors.append("Markdown 代码围栏数量为奇数。")
    if not cpp:
        errors.append("缺少非空的 ```cpp 代码块。")
    elif any(not block.strip() for block in cpp):
        errors.append("存在空的 C++ 代码块。")
    if PLACEHOLDER.search(text):
        errors.append("仍包含 TODO、待补充或尖括号占位内容。")

    if mode == "note":
        if not text.startswith("---\n") and not text.startswith("---\r\n"):
            errors.append("单算法笔记缺少 YAML frontmatter。")
        else:
            end = re.search(r"(?m)^---\s*$", text[4:])
            frontmatter = text[4 : 4 + end.start()] if end else ""
            if not end:
                errors.append("YAML frontmatter 未闭合。")
            else:
                if not re.search(r"(?m)^tags:\s*$", frontmatter):
                    errors.append("frontmatter 缺少 tags。")
                if not re.search(r"(?m)^Time:\s*\S+", frontmatter):
                    errors.append("frontmatter 缺少非空 Time。")

        if not any(name in NOTE_INTRO for name in names):
            errors.append("缺少“定义”“功能”或“介绍”小节。")
        if not any(NOTE_IMPLEMENTATION.search(name) for name in names):
            errors.append("缺少实现或做法小节。")
        if "代码" not in names and not any(name.startswith("代码 ") for name in names):
            errors.append("缺少代码小节。")
        if "例题链接" not in names:
            warnings.append("缺少例题链接小节；没有可靠链接时也可保留空小节。")
        if not any(level == 1 for level, _ in hs):
            warnings.append("缺少一级算法标题；若目标目录沿用旧格式可忽略。")

    if mode == "codebook":
        required = {"作用", "核心思想", "标准代码", "复杂度", "易错点"}
        missing = sorted(required.difference(names))
        if missing:
            errors.append("Codebook 单页缺少小节：" + "、".join(missing) + "。")
        if len(cpp) != 1:
            errors.append("Codebook 单页必须恰好包含一个 C++ 主体代码块。")

    levels = [level for level, _ in hs]
    for previous, current in zip(levels, levels[1:]):
        if current > previous + 1:
            warnings.append(f"标题层级从 H{previous} 跳到 H{current}。")
            break

    if "#define int long long" in text:
        warnings.append("检测到 #define int long long；确认全局替换类型确有必要。")
    if len(cpp) > 2 and mode == "note":
        warnings.append("C++ 代码块超过两个；确认每个版本都有明确的适用差异。")

    return errors, warnings


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("path", type=Path, help="待检查的 Markdown 文件")
    parser.add_argument("--mode", choices=("note", "codebook"), default="note")
    parser.add_argument("--strict", action="store_true", help="将 warning 视为失败")
    args = parser.parse_args()

    errors, warnings = validate(args.path, args.mode)
    for message in errors:
        print(f"error: {message}")
    for message in warnings:
        print(f"warning: {message}")

    if errors or (args.strict and warnings):
        return 1
    print("ok: 结构检查通过。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
