# GD_OTG
GD32单片机U盘升级(OTG)

GD32F103RE

## 构想

设备可以同时使用OTG升级和网络升级

### 服务器

- 服务器要有一个管理列表,给设备分配对应的最新版本号.
- 设备可以向服务器获取最新的版本号,设置自动升级
- 通过http协议进行文件传输.
- *服务器存放的固件要是加密过的.

### 设备

- 设备默认有OTG升级,同时设备可以选择附加选项OTA.

- 设备连接数据线插入电脑后,电脑读出u盘.

- 用户将固件拖入u盘中,设备检测到接收完成新的固件,自动重启.

- 设备从服务器下载最新固件存入文件系统(也就是自身u盘中)下载并校验完成后重启升级

- 设备也可以设置为重启后升级还是立即重启升级.

- *虚拟串口

- 设备升级方式

  1. 上电几秒内检查和电脑的连接,若连接则开启boot盘,否则直接进入APP区.

     -- 适用于无法联网且app区程序不想或不需要添加配合bootloader的程序.

  2. 设备可以在APP区检测数据线连接,以及检测固件是否传输完成.传输完成后可以选择重启升级.

  3. 设备可以通过http协议将固件下载到文件系统中...

- *云端文件系统同步功能.

## 第一阶段

### 驱动开发

1. #### 文件系统+虚拟U盘

## 软件版本:

**正式版本：正在开发...**

-  v23.8c.1.d0.0 -- :
   1. **Major**:项目规划
   2. **Minor**:添加文件系统和虚拟u盘
   3. **Release**:无变更

**版本说明**

| **类型**     | 项目确定号(Year) | 项目确定号(Month)                   | 主版本号(Major)                                              | 次版本号(Minor)                                              | 发布号(Release)                                              |
| ------------ | ---------------- | ----------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **显示**     | u                | w                                   | x                                                            | y                                                            | z                                                            |
| **编号规则** | 项目开始年       | 项目开始月（月份重复时可使用xa,xb） | X从1开始以1为单位递增                                        | X从0开始以1为单位递增                                        | 根据交付质量分以下三种：①正式版本（即交付给客户用于规模商用的版本）：采用x标识，x从1开始（0仅作为正式版）以1为单位递增；②  候选版本（即交付给客户进行测试等受限商用的版本）：采用模式rcx标识， x从1开始以1为单位递增；③  非商用版本（即交付给客户用于比拼、对接、演示等的版本）：采用模式tx标识， x从1开始以1为单位递增。 |
| **承载内容** | 项目起始年月     | 项目起始年月                        | 当功能有一定的增加或变化，比如增加了对权限控制、增加自定义视图等功能。此版本号由项目决定是否修改 | 当功能有一定的增加或变化，比如增加了对权限控制、增加自定义视图等功能。此版本号由项目决定是否修改 | 承载发布的顺序号以及需要显式表达的属性                       |
| **举例**     | 23               | 8                                   | 1                                                            | 0                                                            | .0 .rc1 .t1                                                  |
