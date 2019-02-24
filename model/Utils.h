//
//  Utils.h
//  MacBox
//
//  Created by Mark on 16/08/2017.
//  Copyright © 2017 Mark McGuill. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

#define kStrongboxErrorCodeIncorrectCredentials (-241)

NS_ASSUME_NONNULL_BEGIN

@interface Utils : NSObject

+ (NSError *)createNSError:(NSString *)description errorCode:(NSInteger)errorCode;
+ (NSString *)getAppName;
+ (NSString *)getAppVersion;
+ (NSString *)insertTimestampInFilename:(NSString *)title;
+ (NSString *)hostname;
+ (NSString *)getUsername;
+ (NSString *)trim:(NSString*)string;
+ (NSComparisonResult)finderStringCompare:(NSString*)string1 string2:(NSString*)string2;

+ (void)integerTolittleEndian4Bytes:(int)data bytes:(unsigned char *)b;

NSData* Int64ToLittleEndianData(int64_t integer);
NSData* Int32ToLittleEndianData(int32_t integer);
NSData* Int16ToLittleEndianData(int16_t integer);

NSData* Uint64ToLittleEndianData(uint64_t integer);
NSData* Uint32ToLittleEndianData(uint32_t integer);
NSData* Uint16ToLittleEndianData(uint16_t integer);

int64_t littleEndian8BytesToInt64(uint8_t* bytes);
int32_t littleEndian4BytesToInt32(uint8_t* bytes);
int16_t littleEndian2BytesToInt16(uint8_t *bytes);

uint64_t littleEndian8BytesToUInt64(uint8_t* bytes);
uint32_t littleEndian4BytesToUInt32(uint8_t* bytes);
uint16_t littleEndian2BytesToUInt16(uint8_t *bytes);

int64_t littleEndianNBytesToInt64(uint8_t* bytes, int n);

void hexdump(unsigned char *buffer, unsigned long index, unsigned long width);
+ (NSString *)hexadecimalString:(NSData *)data;

NSData* sha256(NSData *data);
NSData* getRandomData(uint32_t length);
uint32_t getRandomUint32(void);

#if TARGET_OS_IPHONE
UIImage* scaleImage(UIImage* image, CGSize newSize);
#else
NSImage* scaleImage(NSImage* image, CGSize newSize);
#endif

NSString *getDomain(NSString* host);
NSString *getSearchTermFromDomain(NSString* host);

+ (NSData*)getImageDataFromPickedImage:(NSDictionary<UIImagePickerControllerInfoKey,id> *)info error:(NSError**)error;

NS_ASSUME_NONNULL_END

@end
