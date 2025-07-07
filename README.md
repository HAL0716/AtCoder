# AtCoder Setup & Test

## Step 0: Login

```bash
aclogin
```

## Step 1: Setup contest

```bash
bash setup.sh <contest>
```

## Step 2: Test problem

```bash
bash test.sh <contest> <problem>
```

---

## Setup environment

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

---

`config.env`で仮想環境のパスを変更可能です。

---

ファイル構成は以下が基本です：

* `contests/<contest>/<problem>/<problem>.cpp`
* `template.cpp`（コードテンプレート）

---

必要に応じてお使いください！