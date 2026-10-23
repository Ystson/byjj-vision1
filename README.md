<img width="337" height="231" alt="image" src="https://github.com/user-attachments/assets/9cf8bd53-2ec1-4886-af0c-ef855cbc2434" />
<img width="323" height="210" alt="image" src="https://github.com/user-attachments/assets/ede7475e-6d18-4c0d-a68c-f235fe5fdea1" />
<img width="592" height="326" alt="image" src="https://github.com/user-attachments/assets/10c35ad7-da15-47c5-91e1-48c288c3d4a1" />
<img width="239" height="189" alt="image" src="https://github.com/user-attachments/assets/a8b477df-f11e-47a0-8245-091b38462305" />
思路：1.过滤颜色：让电脑把彩色的画面变成黑白的，红色和蓝色的变成白色，其他背景全变黑。
2.然后找白块：电脑去找白块把它圈出来，并挑出真正的灯条（加个条件长宽比大概 2 到 8 之间的，才可能是灯条。）
3.最后给挑出来的灯条画上绿色的实线框。

问题：1.中间会有灯条动着动着绿框缺失一半的情况，应该是视频比较糊灯条又动的比较快导致电脑把那半边识别成背景了。
2.绿框把灯条遮住了不知道会不会有影响，可以后面再调一下
<img width="335" height="164" alt="image" src="https://github.com/user-attachments/assets/7198835d-6276-4ad9-b35a-50aa8c6afed0" />
<img width="175" height="91" alt="image" src="https://github.com/user-attachments/assets/b1383750-0856-48d0-8c88-d79678019a33" />

