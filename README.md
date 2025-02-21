### 概述

控制台文字肉鸽小游戏，能够控制角色向东南西北四个方向移动，每次移动触发[*随机事件*](#section1)，没有终点的旅途，一直勇敢的走下去吧

### 任务列表

-   [x] 玩家设计
-   [x] 玩家属性完善
-   [x] 战斗可控
-   [ ] 武器增加副属性以及武器技能

### 当前界面

```
1.查看玩家信息
2.战斗
3.查看武器图鉴
4.随机装备武器
5.查看怪物图鉴
q.退出游戏
```

### 目标界面

```
```

### 玩家属性设计

+ 玩家名称：让玩家自己创建名字
+ 等级：玩家等级，默认为1
+ 生命值：生命值，没啥好说的
+ 最大生命值：回复生命值时的上限，不会超过此数值
+ 防御力：防御力，也没啥好说的
+ 攻击力：攻击力，还是没啥说的
+ 速度：目前是1v1的对战模式，是否有必要增加这个属性
+ 武器槽：可以装备一把武器，不限制类型
+ 防具槽：肉鸽游戏是否有必要呢
+ 经验值：没啥好说的
+ 经验值上限：经验值达到经验值上限时就会升级
+ 背包：可以存放装备，武器，道具
+ 技能：默认1个技能槽，随着等级增加可以开启更多技能槽，技能槽技能可以更换
+ 玩家获取的技能：通过奖励房间，或者升级，获得的技能组

### 移动设计

以玩家初始化的位置为中心 [ 0 , 0 ] ，距离玩家越远的位置，[奖励越丰富](#section2)，同时怪物的属性值也会随着离中心的距离越远而变高，由于实际操作位走格子，所以原路返回时，应当不再触发随机事件。

### 怪物属性设计

+ 怪物名称：至少给它个名字吧
+ 怪物等级：可以加上，但似乎没啥意义
+ 

### 关键词解释

> <a id="section1">*随机事件*</a>

- 战斗事件，遭遇怪物触发战斗
- 奖励事件，开启宝箱获得装备&道具

> <a id="section2">*奖励越丰富*</a>

+ 装备品质好，属性值高
