# LLM4LoopInvGen
the tool using large language model to automatically generate inductive loop invariants for c program

### V0

| V0                 | Yes  | No   |
| ------------------ | ---- | ---- |
| ACSL               |      | 1    |
| Pre condition      | 1    |      |
| Post condition     | 1    |      |
| Single loop        |      | 1    |
| Symbolic execution | 1    |      |
| Path classify      | 1    |      |
| Feedback           | 1    |      |

### result by gpt-4o
```
========================================
                  统计结果                  
========================================
合法个数：58/66
合法率： 87.88%
----------------------------------------
错误的文件名:
  - loop_57.c
  - loop_55.c
  - loop_4.c
  - loop_11.c
  - loop_58.c
  - loop_54.c
  - loop_35.c
  - loop_56.c
========================================
```





