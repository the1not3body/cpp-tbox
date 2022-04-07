#ifndef TBOX_BASE_LOG_IMP_20180201
#define TBOX_BASE_LOG_IMP_20180201

/**
 * 本文件只声明了函数 LogSetPrintfFunc() 该函数用于指定日志输出函数
 * 如果不指定，则默认不输出日志。
 */

#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//! 日志内容
struct LogContent {
    long thread_id;         //!< 线程ID
    struct {
        uint32_t sec;       //!< 秒
        uint32_t usec;      //!< 微秒
    } timestamp;            //!< 时间戳

    const char *module_id;  //!< 模块名
    const char *func_name;  //!< 函数名
    const char *file_name;  //!< 文件名
    int         line;       //!< 行号
    int         level;      //!< 日志等级
    bool        with_args;  //!< 是否有可变参数
    const char *fmt;        //!< 格式串
    va_list     args;       //!< 可变参数
};

//! 定义日志输出函数
typedef void (*LogPrintfFuncType)(LogContent *content);

//! 添加与删除日志输出函数
uint32_t LogAddPrintfFunc(const LogPrintfFuncType &func);
bool     LogRemovePrintfFunc(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif //TBOX_BASE_LOG_IMP_20180201
