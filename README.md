# LLM4LoopInvGen
the tool using large language model to automatically generate inductive loop invariants for c program

### V0

| V0                 | Yes  | No   |
| ------------------ | ---- | ---- |
| ACSL               | 1    |      |
| Pre condition      |      | 1    |
| Post condition     | 1    |      |
| Single loop        | 1    |      |
| Symbolic execution |      | 1    |
| Path classify      |      | 1    |
| Feedback           |      | 1    |

### result by gpt-4o
```
-----------------------------------------
========================================
                  统计结果
========================================
合法个数：65/65
合法率： 100.00%
有效个数：27/65
有效率： 41.54%
正确个数: 21/65
正确率: 32.31%
----------------------------------------
错误的文件名:
  - loop_13.c
  - loop_65.c
  - loop_51.c
  - loop_42.c
  - loop_43.c
  - loop_62.c
  - loop_7.c
  - loop_12.c
  - loop_46.c
  - loop_14.c
  - loop_5.c
  - loop_64.c
  - loop_22.c
  - loop_29.c
  - loop_59.c
  - loop_34.c
  - loop_4.c
  - loop_11.c
  - loop_60.c
  - loop_32.c
  - loop_6.c
  - loop_26.c
  - loop_31.c
  - loop_28.c
  - loop_63.c
  - loop_52.c
  - loop_9.c
  - loop_24.c
  - loop_48.c
  - loop_50.c
  - loop_16.c
  - loop_3.c
  - loop_41.c
  - loop_53.c
  - loop_36.c
  - loop_35.c
  - loop_61.c
  - loop_44.c
  - loop_30.c
  - loop_27.c
  - loop_38.c
  - loop_37.c
  - loop_21.c
  - loop_18.c
========================================
```

### result by deepseek-v3

```
-----------------------------------------
========================================
                  统计结果
========================================
合法个数：50/65
合法率： 76.92%
有效个数：17/65
有效率： 26.15%
正确个数: 15/65
正确率: 23.08%
----------------------------------------
错误的文件名:
  - loop_13.c
  - loop_33.c
  - loop_65.c
  - loop_51.c
  - loop_42.c
  - loop_43.c
  - loop_62.c
  - loop_7.c
  - loop_12.c
  - loop_46.c
  - loop_15.c
  - loop_8.c
  - loop_14.c
  - loop_5.c
  - loop_64.c
  - loop_22.c
  - loop_29.c
  - loop_17.c
  - loop_59.c
  - loop_19.c
  - loop_34.c
  - loop_4.c
  - loop_11.c
  - loop_60.c
  - loop_32.c
  - loop_6.c
  - loop_26.c
  - loop_31.c
  - loop_28.c
  - loop_63.c
  - loop_52.c
  - loop_40.c
  - loop_9.c
  - loop_24.c
  - loop_48.c
  - loop_25.c
  - loop_16.c
  - loop_3.c
  - loop_53.c
  - loop_36.c
  - loop_47.c
  - loop_35.c
  - loop_61.c
  - loop_20.c
  - loop_44.c
  - loop_30.c
  - loop_38.c
  - loop_37.c
  - loop_21.c
  - loop_18.c
========================================
```



