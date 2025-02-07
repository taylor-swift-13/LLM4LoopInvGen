# LLM4LoopInvGen
the tool using large language model to automatically generate inductive loop invariants for c program

### V1

| V1                 | Yes  | No   |
| ------------------ | ---- | ---- |
| ACSL               | 1    |      |
| Pre condition      | 1    |      |
| Post condition     | 1    |      |
| Single loop        | 1    |      |
| Symbolic execution | 1    |      |
| Path classify      | 1    |      |
| Feedback           |      | 1    |

### result for gpt-4o

```
-----------------------------------------
========================================
                  统计结果                  
========================================
合法个数：64/65
合法率： 98.46%
有效个数：53/65
有效率： 81.54%
正确个数: 53/65
正确率: 81.54%
----------------------------------------
错误的文件名:
  - loop_62.c
  - loop_64.c
  - loop_17.c
  - loop_63.c
  - loop_40.c
  - loop_16.c
  - loop_36.c
  - loop_35.c
  - loop_61.c
  - loop_27.c
  - loop_38.c
  - loop_37.c
========================================
```

### result for deepseek-v3

```
-----------------------------------------
========================================
                  统计结果                  
========================================
合法个数：57/65
合法率： 87.69%
有效个数：47/65
有效率： 72.31%
正确个数: 45/65
正确率: 69.23%
----------------------------------------
错误的文件名:
  - loop_62.c
  - loop_7.c
  - loop_23.c
  - loop_15.c
  - loop_64.c
  - loop_17.c
  - loop_63.c
  - loop_40.c
  - loop_9.c
  - loop_24.c
  - loop_25.c
  - loop_16.c
  - loop_36.c
  - loop_47.c
  - loop_54.c
  - loop_35.c
  - loop_61.c
  - loop_20.c
  - loop_38.c
  - loop_37.c
========================================
```

