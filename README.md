# com4table keymap

con4t4ble のコンセプトを受け継ぎながら、発生した問題点を改善したもの。

## 使い方

自分のqmk_firmwareリポジトリでsubmoduleとして参照する。

```shell
git submodule add  git@github.com:bigwheel/qmk_firmware-users-com4table.git users/com4table
```

## 機能

### 記号入力のときは自動で日本語入力 OFF

ここは con4t4ble と変わらず。

### 一定時間キー入力なしで日本語入力自動 OFF

ここは con4t4ble と変わらず。

### OS 間のキー配置差分吸収

PC と MAC 間のキー配置の差分を吸収する機能。
以下のキーを OS に合わせたキーコードへ変更する。

-   Windows キー(Command キー)
-   Alt キー(Option キー)
-   変換キー(かなキー)
-   無変換キー(英数キー)

#### 使い方

そのキーボードを使いたい OS が PC なら

```c
#define MAC_KEYMAP 0
```

MAC なら

```c
#define MAC_KEYMAP 1
```

のどちらかを config.h に記述する。

#### 備考: デフォルトレイヤーによる PC/MAC 切り替えとこちらのどちらを使うか

基本的にはデフォルトレイヤーのほうが便利。
ただし、デフォルトレイヤーの切り替えは[コードを書かないと](https://docs.qmk.fm/#/ref_functions?id=setting-the-persistent-default-layer)永続化されず、再起動や USB ケーブルの抜き差しで消えてしまう。

また、Halberd のように一部のキーをコンボキーにしていると、その部分はデフォルトレイヤー依存にすることはできない。

両 OS コンパチキーマップにはそういった諸々の複雑さがあるため、それらを避けてファームウェア的には 1 種類の OS 用ながら簡単に PC / MAC を切り替えられる。それがこの機能の利点になる。

### デフォルトのprocess_record_user宣言機能

自分で定義したい場合は次の宣言を `config.h` で行う。

```c
#define CUSTOM_PROCESS_RECORD_USER
```

### Caravelle互換機能

Caravelle-BLEは専用のブランチでビルドする必要があるが、そのブランチの
ベースが数年前のqmk_firmwareであるため一部の最新関数が入っておらず、userspaceの機能定義にも支障をきたしている。
そこで、このuserspaceの定義に必要な機能をbackportしている。
それを使う場合は次の宣言を `config.h` で行う。

```c
#define CARAVELLE_BACKWARD_FUNC
```

## BMP(BLE Micro Proについて)

基本的にはそのまま動くが、 `LEFT_OF_LEFT_LANG_KEY` などのキーコードは使えない(BMPのjson内では#defineを参照しないため)。
