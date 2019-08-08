#ifndef _GZINJECT_H_
#define _GZINJECT_H_

#include <stddef.h>

#define REVERSEENDIAN32(X)  (((X) >> 24) & 0xff) | (((X)<<8) & 0xFF0000) | (((X) >> 8) & 0xff00) | (((X)<<24) & 0xff000000)
#define REVERSEENDIAN16(X) (((X)>>8) & 0xff) | (((X)<<8) & 0xFF00)

#define W_TIK 0x00
#define W_TMD 0x01
#define GZINJECT_VERSION "0.3.0"

typedef enum{
    FILE_DIRECTORY,
    FILE_NORMAL
}filetype_t;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

u16 be16(const u8 *p);
u32 be32(const u8 *p);

u32 getcontentlength(u8 *, unsigned int);
u32 addpadding(unsigned int, unsigned int);
void truchasign(u8 *, u8, size_t);
void removefile(const char *);
void removedir(const char *);
char *removeext(char *);
void genkey();
void do_extract();
void do_pack(const char*,const char*);
void print_usage();
void print_version();
#endif
