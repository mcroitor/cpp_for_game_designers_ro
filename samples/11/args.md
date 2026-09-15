# Explicatie la cod

Acest cod demonstreaza cum se utilizează argumenti a punctului de intrare aplicatiei. This is a **test**.

here is another paragraph.

```cpp
#include <cstdio>

int main(int argc, char** argv) {
    for(int i = 0; i < argc; ++i) {
        printf("argv[ %d ] = %s\n", i, argv[i]);
    }
    return 0;
}
```

- [ ] `argc` - numarul de argumente
- [x] `argv` - vector de argumente

| **argument** | *value* |
| ------------ | ------- |
| width        | 80      |
| height       | 32      |
