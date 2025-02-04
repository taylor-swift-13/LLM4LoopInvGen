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
有效个数：50/65
有效率： 76.92%
正确个数: 38/65
正确率: 58.46%
----------------------------------------
错误的文件名:
  - loop_51.c
  - loop_42.c
  - loop_43.c
  - loop_62.c
  - loop_46.c
  - loop_15.c
  - loop_64.c
  - loop_17.c
  - loop_59.c
  - loop_60.c
  - loop_26.c
  - loop_31.c
  - loop_63.c
  - loop_40.c
  - loop_24.c
  - loop_48.c
  - loop_16.c
  - loop_53.c
  - loop_36.c
  - loop_35.c
  - loop_61.c
  - loop_20.c
  - loop_44.c
  - loop_38.c
  - loop_37.c
  - loop_21.c
  - loop_18.c
========================================
```

### result for deepseek-r1

```
-----------------------------------------
========================================
                  统计结果
========================================
有效个数：60/65
有效率： 92.31%
正确个数: 42/65
正确率: 64.62%
----------------------------------------
错误的文件名:
  - loop_13.c
  - loop_65.c
  - loop_51.c
  - loop_42.c
  - loop_43.c
  - loop_62.c
  - loop_46.c
  - loop_59.c
  - loop_19.c
  - loop_60.c
  - loop_6.c
  - loop_26.c
  - loop_45.c
  - loop_63.c
  - loop_40.c
  - loop_24.c
  - loop_48.c
  - loop_53.c
  - loop_61.c
  - loop_44.c
  - loop_38.c
  - loop_21.c
  - loop_18.c
========================================
```

