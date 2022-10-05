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
directory_path="/home/hiraku/kyopro/AtCoder/"
# ファイルとディレクトリのパスを取得
# エイリアスの設定に合わせてどのディレクトリ下でも使えるように絶対パスに変更
if [ ${s:0:3} = "abc" ]; then
    DIL="${directory_path}ABC/${s:3:3}"
    FILE="${directory_path}ABC/${s:3:3}/${ARR[-1]}.cpp"
elif [ ${s:0:3} = "arc" ]; then
    DIL="${directory_path}ARC/${s:3:3}"
    FILE="${directory_path}ARC/${s:3:3}/${ARR[-1]}.cpp"
elif [ ${s:0:3} = "agc" ]; then
    DIL="${directory_path}AGC/${s:3:3}"
    FILE="${directory_path}AGC/${s:3:3}/${ARR[-1]}.cpp"
elif [ ${s:0:3} = "ahc" ]; then
    DIL="${directory_path}AHC/${s:3:3}"
    FILE="${directory_path}AHC/${s:3:3}/${ARR[-1]}.cpp"
elif [ ${s:0:3} = "dp_" ]; then
    DIL="${directory_path}others/edpc"
    FILE="${directory_path}others/edpc/${ARR[-1]}.cpp"
else
    DIL="${directory_path}others/${ARR[3]}"
    FILE="${directory_path}others/${ARR[3]}/${ARR[-1]}.cpp"
fi

# ファイルが存在しない場合に作成
if [ ! -e $FILE ]; then
    mkdir -p $DIL
    touch $FILE
    cp ${directory_path}template.cpp $FILE
    # ファイルへの追記
    # https://www.delftstack.com/ja/howto/linux/how-to-append-text-to-a-file-using-bash/
    sed -e "9a // 問題\n// ${pPATH}\n" ${directory_path}template.cpp > $FILE
fi



