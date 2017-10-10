# VideoPlsInterfaceContronller
###1.8.2
1. 修复子商城全屏webView打开货架未关闭的问题
2. 增加子商城竖屏webView关闭对外通知
3. 修复子商城login登陆回调2次的错误

###1.8.1
1. 修复VPUPPubWebView初始化为nil的问题

###1.8.0
1. 添加子商城入口
2. 添加获取用户、设置用户代理
3. 添加webView使用

###1.7.5

###1.7.4

###1.7.3
1. 修正直播webview通知通过playback的string

###1.7.2
1. 修复直播发通知未接收到的bug

###1.7.1
1. 修复直播platformID未设置成功的bug

###1.7.0
1. 添加暂停业务接口

###1.6.0
1. 修复设备旋转触发faceup,facedown导致全屏显示不正常
2. 添加action监控的界面显示
3. 修复cytronView和liveView没有包在宏中

###1.5.0
1. 新增对外曝光通用接口 vp_interfaceActionNotify 详见 VPinterfaceStatusNotifyDelegate.h
2. 添加webP支持,设置appKey参数接口变成 setAppKey:platformID:useWebP: ,如果对接使用了Pod的SDWebImage/webP, 则可以将useWebP置为YES,减少加载图片的流量开销
3. 平台层已移除公用Pod库,dependency中包含AFNetworking~>3.0, SDWebImage~>4.0


###1.4.0
1. 移除对接层对外暴露点播枚举参数


###1.3.6
1. 对接层项目初始化
