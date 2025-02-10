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
合法个数：65/65
合法率： 100.00%
有效个数：54/65
有效率： 83.08%
正确个数: 53/65
正确率: 81.54%
----------------------------------------
错误的文件名:
  - loop_62.c
  - loop_46.c
  - loop_64.c
  - loop_32.c
  - loop_63.c
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
========================================
                  统计结果
========================================
合法个数：62/65
合法率： 95.38%
有效个数：49/65
有效率： 75.38%
正确个数: 46/65
正确率: 70.77%
----------------------------------------
错误的文件名:
  - loop_62.c
  - loop_7.c
  - loop_23.c
  - loop_15.c
  - loop_8.c
  - loop_64.c
  - loop_63.c
  - loop_40.c
  - loop_9.c
  - loop_50.c
  - loop_25.c
  - loop_16.c
  - loop_10.c
  - loop_36.c
  - loop_47.c
  - loop_35.c
  - loop_61.c
  - loop_38.c
  - loop_37.c
========================================
```

