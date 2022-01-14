#ifndef _APP_DEBUG_H_
#define _APP_DEBUG_H_

#include "user_config.h"

#define APP_DEBUG_SW
#define APP_COLOR_SW
//#define APP_FILE_FUNC_LINE_SHOW


#define APP_LEVEL_ERROR     0
#define APP_LEVEL_WARN      1
#define APP_LEVEL_INFO      2
#define APP_LEVEL_TRACE     3
#define APP_LEVEL_NUM       4

#define APP_DEBUG_LEVEL    APP_LEVEL_INFO

#ifdef APP_COLOR_SW 
#define APP_COLOR_NONE          "\033[m" 
#define APP_COLOR_LIGHT_RED     "\033[1;31m"  
#define APP_COLOR_RED           "\033[0;32;31m"
#define APP_COLOR_BLUE          "\033[0;32;34m"
#define APP_COLOR_GREEN         "\033[0;32;32m"
#else
#define APP_COLOR_NONE   
#define APP_COLOR_LIGHT_RED  
#define APP_COLOR_RED        
#define APP_COLOR_BLUE      
#define APP_COLOR_GREEN
#endif /* APP_COLOR_SW */


#ifdef APP_DEBUG_SW 
#define APP_PRINTF(fmt, ...)    printf(fmt, ##__VA_ARGS__) 
#else
#define APP_PRINTF(fmt, ...)
#endif  /* APP_DEBUG_SW */


#ifdef APP_FILE_FUNC_LINE_SHOW
#define app_printf(fmt, ...)     APP_PRINTF("(%s)(%s)(%d)"fmt"\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define app_printf(fmt, ...)     APP_PRINTF(fmt"\r\n", ##__VA_ARGS__)
#endif /* APP_FILE_FUNC_LINE_SHOW */



#if (APP_DEBUG_LEVEL >= APP_LEVEL_TRACE)
#define app_printe(fmt, ...)    APP_PRINTF(APP_COLOR_LIGHT_RED "[error](%s)(%s)(%d)"fmt APP_COLOR_NONE"\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printw(fmt, ...)    APP_PRINTF(APP_COLOR_RED "[warn](%s)(%s)(%d)"fmt APP_COLOR_NONE"\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printi(fmt, ...)    app_printf(APP_COLOR_BLUE "[info]"fmt APP_COLOR_NONE, ##__VA_ARGS__)
#define app_printt(fmt, ...)    app_printf(APP_COLOR_GREEN "[trace]"fmt APP_COLOR_NONE, ##__VA_ARGS__)
#define app_dprinte(pdata, len)  do {APP_PRINTF(APP_COLOR_LIGHT_RED "[error](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintw(pdata, len)  do {APP_PRINTF(APP_COLOR_RED "[warn](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprinti(pdata, len)  do {APP_PRINTF(APP_COLOR_BLUE "[info](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintt(pdata, len)  do {APP_PRINTF(APP_COLOR_GREEN "[trace](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)

#elif (APP_DEBUG_LEVEL >= APP_LEVEL_INFO)
#define app_printe(fmt, ...)    APP_PRINTF(APP_COLOR_LIGHT_RED "[error](%s)(%s)(%d)"fmt APP_COLOR_NONE "\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printw(fmt, ...)    APP_PRINTF(APP_COLOR_RED "[warn](%s)(%s)(%d)"fmt APP_COLOR_NONE "\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printi(fmt, ...)    app_printf(APP_COLOR_BLUE "[info]"fmt APP_COLOR_NONE, ##__VA_ARGS__)
#define app_printt(fmt, ...)
#define app_dprinte(pdata, len)  do {APP_PRINTF(APP_COLOR_LIGHT_RED "[error](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintw(pdata, len)  do {APP_PRINTF(APP_COLOR_RED "[warn](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprinti(pdata, len)  do {APP_PRINTF(APP_COLOR_BLUE "[info](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintt(pdata, len)

#elif (APP_DEBUG_LEVEL >= APP_LEVEL_WARN)
#define app_printe(fmt, ...)    APP_PRINTF(APP_COLOR_LIGHT_RED "[error](%s)(%s)(%d)"fmt APP_COLOR_NONE "\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printw(fmt, ...)    APP_PRINTF(APP_COLOR_RED "[warn](%s)(%s)(%d)"fmt APP_COLOR_NONE "\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printi(fmt, ...)
#define app_printt(fmt, ...)
#define app_dprinte(pdata, len)  do {APP_PRINTF(APP_COLOR_LIGHT_RED "[error](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintw(pdata, len)  do {APP_PRINTF(APP_COLOR_RED "[warn](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprinti(pdata, len)
#define app_dprintt(pdata, len)

#elif (APP_DEBUG_LEVEL >= APP_LEVEL_ERROR)
#define app_printe(fmt, ...)    APP_PRINTF(APP_COLOR_LIGHT_RED "[error](%s)(%s)(%d)"fmt APP_COLOR_NONE "\r\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define app_printw(fmt, ...)
#define app_printi(fmt, ...)
#define app_printt(fmt, ...)
#define app_dprinte(pdata, len)  do {APP_PRINTF(APP_COLOR_LIGHT_RED "[error](data len:%d) ", len);for(int i = 0; i < len; i ++){APP_PRINTF("%02x ", (pdata)[i]);}APP_PRINTF(APP_COLOR_NONE"\r\n");} while(0)
#define app_dprintw(pdata, len)
#define app_dprinti(pdata, len)
#define app_dprintt(pdata, len)

#endif /* APP_DEBUG_LEVEL */







#endif

