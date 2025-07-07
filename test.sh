#!/bin/bash
set -euo pipefail

[ -f "config.env" ] && source config.env

VENV_DIR="${VENV_DIR:-.venv}"

activate_venv() {
  [ -f "$VENV_DIR/bin/activate" ] && source "$VENV_DIR/bin/activate" || { echo "No venv: $VENV_DIR"; exit 1; }
}

check_args() {
  if [ $# -ne 2 ]; then
    echo "❌ 使い方: bash test.sh <contest> <problem>"
    exit 1
  fi
}

download_testcases_if_needed() {
  local contest="$1" problem="$2"
  local test_dir="contests/$contest/$problem/testcase"

  mkdir -p "$test_dir"
  if [ -z "$(ls -A "$test_dir")" ]; then
    echo "⬇️ テストデータをダウンロード中..."
    oj d "https://atcoder.jp/contests/$contest/tasks/${contest}_${problem}" -d "$test_dir"
  fi
}

build_cpp() {
  local cpp_file="$1" output="$2"
  g++ -std=c++20 -O2 "$cpp_file" -o "$output"
}

run_test() {
  local input="$1" expected="$2" exec="$3"

  local output
  output=$(./"$exec" < "$input")
  local expected_output
  expected_output=$(<"$expected")

  if diff -u <(echo "$expected_output") <(echo "$output") > /dev/null; then
    echo "✅ $(basename "$input")"
  else
    echo "❌ $(basename "$input")"
    echo "--- 期待値 ---"
    echo "$expected_output"
    echo "--- 実行結果 ---"
    echo "$output"
    return 1
  fi
}

# 全体テスト
run_all_tests() {
  local contest="$1" problem="$2" exec="$3"
  local test_dir="contests/$contest/$problem/testcase"
  local all_passed=true

  for in_file in "$test_dir"/*.in; do
    local out_file="${in_file%.in}.out"
    if [ -f "$out_file" ]; then
      run_test "$in_file" "$out_file" "$exec" || all_passed=false
    fi
  done

  if $all_passed; then
    echo "🎉 全てのテストケースを通過しました"
  else
    echo "⚠️ テスト失敗"
    exit 1
  fi
}

main() {
  activate_venv
  check_args "$@"

  local contest="$1" problem="$2"
  local cpp_file="contests/$contest/$problem/$problem.cpp"
  local exec="$problem"

  trap "rm -f \"$exec\"" EXIT

  build_cpp "$cpp_file" "$exec"
  download_testcases_if_needed "$contest" "$problem"
  run_all_tests "$contest" "$problem" "$exec"
  rm "$exec"
}

main "$@"