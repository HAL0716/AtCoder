#!/bin/bash

[ -f "config.env" ] && source config.env

VENV_DIR="${VENV_DIR:-.venv}"
TEMPLATE_PATH="${TEMPLATE_PATH:-template.cpp}"

check_args() {
  [ -z "$1" ] && { echo "Usage: bash setup.sh <contest>"; exit 1; }
}

create_contest_dir() {
  mkdir -p "contests/$1"
}

create_problem_dirs() {
  local contest="$1"
  for problem in a b c d e f; do
    local prob_dir="contests/$contest/$problem"
    local testcase_dir="$prob_dir/testcase"
    mkdir -p "$testcase_dir"
    cp "$TEMPLATE_PATH" "$prob_dir/$problem.cpp"
    if sed --version >/dev/null 2>&1; then
      sed -i "s/<contest>/$contest/g; s/<problem>/$problem/g" "$prob_dir/$problem.cpp"
    else
      sed -i '' "s/<contest>/$contest/g; s/<problem>/$problem/g" "$prob_dir/$problem.cpp"
    fi
    echo "Downloading $problem testcases..."
    oj d "https://atcoder.jp/contests/$contest/tasks/${contest}_${problem}" -d "$testcase_dir"
  done
}

activate_venv() {
  [ -f "$VENV_DIR/bin/activate" ] && source "$VENV_DIR/bin/activate" || { echo "No venv: $VENV_DIR"; exit 1; }
}

main() {
  activate_venv
  check_args "$1"
  create_contest_dir "$1"
  create_problem_dirs "$1"
  echo "$1 setup done"
}

main "$1"