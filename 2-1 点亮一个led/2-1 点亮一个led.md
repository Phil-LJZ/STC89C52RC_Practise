# 2-1 点亮一个led

1. 新建项目
   ![image-20250220184341602](D:\User\Kechuangbu\Documents\Projects\KeilProject\STC89C52RC\笔记\2-1 点亮一个led\image-20250220184341602.png)

2. 注意事项，勾选以生成hex工程文件
   ![image-20250220184744227](D:\User\Kechuangbu\Documents\Projects\KeilProject\STC89C52RC\笔记\2-1 点亮一个led\image-20250220184744227.png)

3. 更改字体
   ![image-20250220184944534](D:\User\Kechuangbu\Documents\Projects\KeilProject\STC89C52RC\笔记\2-1 点亮一个led\image-20250220184944534.png)

4. led正负极判断
   ![image-20250220185115990](D:\User\Kechuangbu\Documents\Projects\KeilProject\STC89C52RC\笔记\2-1 点亮一个led\image-20250220185115990.png)
   下图左边是正级右边是负极
   ![image-20250220185144340](C:\Users\Kechuangbu\AppData\Roaming\Typora\typora-user-images\image-20250220185144340.png)

5. 单片机led亮灭原理
   ![image-20250220185453143](C:\Users\Kechuangbu\AppData\Roaming\Typora\typora-user-images\image-20250220185453143.png)

   led原理：led正极为高电压，负极为低电压，则亮，反之则灭。
   led正极通过一个限流电阻和vcc链接，如果负极的gpio（例如：P20)如果是低电平（零伏)，那么led的正极是高电压，负极是低电压，此时有电流从负极流向正极，那么led亮，如果gpio是高电平（5伏)，那么led的正极是低电压（应为有电阻分压了)，负极是高电压，那么电流从正极流向负极，此时led不亮。

6. 单片机mcu控制引脚原理：
   单片机中有很多寄存器（例如P2)。寄存器是一种存储器，其中寄存器分为八位，分别叫做P20 P21 P22 P23 P24 P25 P26 P27（其中P20对应0x00八位二进制中的最低位零位，其余的以此类推），每一组链接有一条线，线接到了一个驱动器，驱动器用于增大电流，然后驱动器连到IO口。MCU中的CPU可以通过程序直接访问寄存器，给寄存器写值。**CPU通过配置这些控制的寄存器来控制硬件电路，然后硬件电路来执行我们想要完成的任务**。
   ![image-20250221122010536](D:\User\Kechuangbu\Documents\Projects\KeilProject\STC89C52RC\笔记\2-1 点亮一个led\image-20250221122010536.png)
   例如：将寄存器的第零位设置成1（即0xfe, 11111110)，则对应控制的驱动器将gpio的电平设置为高电平，则led正极为低电压，负极为高电压，led不亮，反之设置为低电平，led亮。

7. 程序运行逻辑：单片机会重复执行main()主函数