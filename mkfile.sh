#! /bin/bash

# 文字列の入力と分割について
# https://genzouw.com/entry/2019/12/17/120057/1831/
# https://qiita.com/toshihirock/items/17c1719e722e94564252

# URLのスラッシュを空白に置き換えて分割
ARR=( `echo $1 | tr -s '/' ' '`)
pPATH=$1
# 配列の末尾の要素
echo "${ARR[-1]}のファイルを作成"


# 文字列分割と条件分岐
# https://qiita.com/koara-local/items/04d3efd1031ea62d8db5
# https://www.delftstack.com/ja/howto/linux/how-to-compare-strings-in-bash/
# ファイルの有無
# https://www.server-memo.net/shellscript/file_check.html

# URLの末尾を取得
s=${ARR[-1]}
# ファイルとディレクトリのパスを取得
if [ ${s:0:3} = "abc" ]; then
    DIL="ABC/${s:3:3}"
    FILE="ABC/${s:3:3}/${s: -1}.cpp"
elif [ ${s:0:3} = "arc" ]; then
    DIL="ARC/${s:3:3}"
    FILE="ARC/${s:3:3}/${s: -1}.cpp"
elif [ ${s:0:3} = "agc" ]; then
    DIL="AGC/${s:3:3}"
    FILE="AGC/${s:3:3}/${s: -1}.cpp"
elif [ ${s:0:3} = "ahc" ]; then
    DIL="AHC/${s:3:3}"
    FILE="AHC/${s:3:3}/${s: -1}.cpp"
else
    DIL="others/${ARR[3]}"
    FILE="others/${ARR[3]}/${s: -1}.cpp"
fi

# ファイルが存在しない場合に作成
if [ ! -e $FILE ]; then
    mkdir -p $DIL
    touch $FILE
    cp template.cpp $FILE
    # ファイルへの追記
    # https://www.delftstack.com/ja/howto/linux/how-to-append-text-to-a-file-using-bash/
    sed -e "9a // 問題\n// ${pPATH}\n" template.cpp > $FILE
fi



