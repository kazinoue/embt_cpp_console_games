# C++Builder Console Games
このプログラムは、平成５年６月２５日に発行された書籍「ゲーム＆＆オブジェクト指向プログラミング BORLAND TURBO C++」を基に[C++Builder 10.2.3](https://www.embarcadero.com/jp/products/cbuilder)用に一部変更し、動作確認したものです。


## [C++Builder](https://www.embarcadero.com/jp/products/cbuilder)コマンドライン起動

このプログラムは、cmake＋ninjaでビルドします。
http://docwiki.embarcadero.com/RADStudio/Tokyo/en/Using_CMake_with_C%2B%2B_Builder    
それにはC++Builder付属のrsvarsバッチファイル実行が必要です。

```bat
cd "C:\Program Files (x86)\Embarcadero\Studio\19.0\bin"
rsvars.bat
```

## CMakeLists.txt
下記CMakeLists.txtには、VCLとDynamicRuntimeを入れています。

```cmake
cmake_minimum_required(VERSION 3.10)
project("cppgames")
set_embt_target(VCL DynamicRuntime)

file(GLOB SOURCES
    "*.h"
    "*.cpp"
)

add_executable("cppgames"   ${SOURCES})
```


## ビルド方法

### 64ビットでビルドする場合

```bat
cmake -DCMAKE_C_COMPILER=bcc64.exe -DCMAKE_CXX_COMPILER=bcc64.exe -G Ninja .\
ninja
```

### 32ビットでビルドする場合
```bat
cmake -DCMAKE_C_COMPILER=bcc32x.exe -DCMAKE_CXX_COMPILER=bcc32x.exe -G Ninja .\
ninja
```


