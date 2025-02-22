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
合法个数：61/65
合法率： 93.85%
----------------------------------------
错误的文件名:
  - loop_13.c
  - loop_15.c
  - loop_14.c
  - loop_40.c
  - loop_27.c
========================================
```





