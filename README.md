# Huffzip

`huffzip` is a C++20 file compressor and decompressor project for a Huffman-coding implementation.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/huffzip --help
```

On Windows with a single-config generator, the executable may be under `build/Debug/huffzip.exe`.

## Test

```bash
ctest --test-dir build --output-on-failure
```

