#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"

build_dir="${TMPDIR:-/tmp}/yuki592_score_bins"
work_dir="${TMPDIR:-/tmp}/yuki592_score_work"
mkdir -p "$build_dir" "$work_dir"

mapfile -t sources < <(find . -maxdepth 1 -name '*.cpp' -printf '%f\n' | sort)

if [ "$#" -gt 0 ]; then
  inputs=("$@")
else
  mapfile -t inputs < <(find in -maxdepth 1 -name '*.txt' | sort)
fi

if [ "${#sources[@]}" -eq 0 ]; then
  echo "no cpp files found" >&2
  exit 1
fi

if [ "${#inputs[@]}" -eq 0 ]; then
  echo "no input files found" >&2
  exit 1
fi

score_output() {
  local input_file="$1"
  local output_file="$2"

  python3 - "$input_file" "$output_file" <<'PY'
import sys
from pathlib import Path

inp = Path(sys.argv[1]).read_text().split()
out = Path(sys.argv[2]).read_text().split()

N, T = map(int, inp[:2])
values = list(map(int, inp[2:2 + N * N]))

try:
    L = int(out[0])
    pts = [(int(out[i]), int(out[i + 1])) for i in range(1, len(out), 2)]
except Exception:
    print("INVALID")
    raise SystemExit

ok = 1 <= L <= T and len(pts) == L
ok = ok and all(0 <= i < N and 0 <= j < N for i, j in pts)
ok = ok and len(set(pts)) == L
ok = ok and all(abs(pts[k][0] - pts[k - 1][0]) + abs(pts[k][1] - pts[k - 1][1]) == 1 for k in range(1, L))

if not ok:
    print("INVALID")
else:
    print(sum(values[i * N + j] for i, j in pts))
PY
}

declare -A bin_of
declare -A total

for src in "${sources[@]}"; do
  name="${src%.cpp}"
  bin="$build_dir/$name"
  echo "compile $src" >&2
  g++ -std=c++17 -O2 -Wall -Wextra "$src" -o "$bin"
  bin_of["$src"]="$bin"
  total["$src"]=0
done

printf '| input |'
for src in "${sources[@]}"; do
  printf ' %s |' "${src%.cpp}"
done
printf '\n'

printf '|---|'
for _ in "${sources[@]}"; do
  printf '%s' '---:|'
done
printf '\n'

for input in "${inputs[@]}"; do
  printf '| %s |' "$input"
  for src in "${sources[@]}"; do
    name="${src%.cpp}"
    out_file="$work_dir/${name}_$(basename "$input").out"
    err_file="$work_dir/${name}_$(basename "$input").err"

    "${bin_of[$src]}" < "$input" > "$out_file" 2> "$err_file"
    score="$(score_output "$input" "$out_file")"

    if [ "$score" = "INVALID" ]; then
      printf ' INVALID |'
    else
      total["$src"]=$((total["$src"] + score))
      printf ' %s |' "$score"
    fi
  done
  printf '\n'
done

printf '| TOTAL |'
for src in "${sources[@]}"; do
  printf ' %s |' "${total[$src]}"
done
printf '\n'
