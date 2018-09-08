//
//  UCLBRTQRBSDK.h
//  QRBSDK
//
//  Created by myApple on 2018/8/21.
//  Copyright © 2018年 myApple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^resultBlock)(NSString * successStr,NSString * errorStr);
typedef void(^fetchKeyBlock)(id view,NSString * errorStr);

@interface QRMasterBTSDK : NSObject

/**
 接口身份初始化,必须先调用这个接口

 @param sid 锁掌柜开发者账号的 Account SID
 @param token 锁掌柜开发者账号的 Auth Token
 */
-(instancetype)initWithSid:(NSString *)sid withToken:(NSString *)token;


/**
 创建房卡
 
 @param mobile 手机号码
 @param communityNo 集群编号  锁掌柜获取
 @param buildNo 楼栋编号  锁掌柜的楼栋编号
 @param floorNo 楼层编号  锁掌柜的楼层编号
 @param roomNo 房间编号   锁掌柜的房间编号
 @param startTime 蓝牙钥匙的开始时间
 @param endTime 蓝牙钥匙的结束时间
 @param areaCode 手机区号 传空则为86
 @param block 请求的数据回调
 */
-(void)generatorKeyWithMobile:(NSString *)mobile withCommunityNo:(NSString *)communityNo withBuildNo:(NSString *)buildNo withFloorNo:(NSString *)floorNo withRoomNo:(NSString *)roomNo withStartTime:(NSString *)startTime withEndTime:(NSString *)endTime withAreaCode:(NSString *)areaCode block:(resultBlock)block;

/**
 通过唯一标示获取蓝牙钥匙开锁
 
 @param communityNo 锁掌柜对应集群编号
 @param areacode 电话区号，默认86，可以传nil
 @param mobile 电话号码，需要和生成钥匙的电话号码一样
 @param cardNo 生成钥匙接口返回的卡的唯一标示
 @param block 请求的数据回调
 */
-(void)fetchKeyWithCommunityNo:(NSString *)communityNo withAreacode:(NSString *)areacode withMobile:(NSString *)mobile withCardNo:(NSString *)cardNo block:(fetchKeyBlock)block;



/**
 通过房间数据获取钥匙  注意：用此方法生成房卡，数据需要和生成房卡的参数完全一致。

 @param communityNo 集群编号
 @param buildNo 楼栋编号
 @param floorNo 楼层编号
 @param roomNo 房间编号
 @param startTime 开始时间  应该大于或者等于生成钥匙的开始时间
 @param endTime 结束时间  应该小于或者等于生成钥匙的结束时间
 @param areacode 电话区号，默认86，可以传nil
 @param mobile 获取钥匙的手机号码
 @param block 请求的数据回调
 */
-(void)fetchKeyRoomNoWithCommunityNo:(NSString *)communityNo withBuildNo:(NSString *)buildNo withFloorNo:(NSString *)floorNo withroomNo:(NSString *)roomNo withStartTime:(NSString *)startTime withEndTime:(NSString *)endTime withAreacode:(NSString *)areacode withMobile:(NSString *)mobile block:(fetchKeyBlock)block;



/**
 失效蓝牙钥匙

 @param cardNo 生成钥匙的唯一标示
 @param block 请求的数据回调
 */
-(void)invalidKeyWithCardNo:(NSString *)cardNo block:(resultBlock)block;


/**
 取消蓝牙连接
 */
-(void)cancelBlueToothConnect;

@end
