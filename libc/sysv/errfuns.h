#ifndef COSMOPOLITAN_LIBC_SYSV_ERRFUNS_H_
#define COSMOPOLITAN_LIBC_SYSV_ERRFUNS_H_
#include "libc/errno.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)

/**
 * @fileoverview Optimized error return paths.
 *
 * Saying this:
 *
 *     return einval();
 *
 * Instead of this:
 *
 *     errno = EINVAL;
 *     return -1;
 *
 * Allows the compiler to generate 11 fewer bytes of code each time.
 *
 * @return always -1
 * @see libc/sysv/errfuns.inc (for implementation)
 */

#define __ERRFUN(FUNC)                              \
  ({                                                \
    intptr_t NegOne;                                \
    asm("call\t" FUNC : "=a"(NegOne), "=m"(errno)); \
    NegOne;                                         \
  })

int einval(void) relegated;

#define eperm()           __ERRFUN("eperm")
#define enoent()          __ERRFUN("enoent")
#define esrch()           __ERRFUN("esrch")
#define eintr()           __ERRFUN("eintr")
#define eio()             __ERRFUN("eio")
#define enxio()           __ERRFUN("enxio")
#define e2big()           __ERRFUN("e2big")
#define enoexec()         __ERRFUN("enoexec")
#define ebadf()           __ERRFUN("ebadf")
#define echild()          __ERRFUN("echild")
#define eagain()          __ERRFUN("eagain")
#define enomem()          __ERRFUN("enomem")
#define eacces()          __ERRFUN("eacces")
#define efault()          __ERRFUN("efault")
#define enotblk()         __ERRFUN("enotblk")
#define ebusy()           __ERRFUN("ebusy")
#define eexist()          __ERRFUN("eexist")
#define exdev()           __ERRFUN("exdev")
#define enodev()          __ERRFUN("enodev")
#define enotdir()         __ERRFUN("enotdir")
#define eisdir()          __ERRFUN("eisdir")
#define enfile()          __ERRFUN("enfile")
#define emfile()          __ERRFUN("emfile")
#define enotty()          __ERRFUN("enotty")
#define enotsup()         __ERRFUN("enotsup")
#define etxtbsy()         __ERRFUN("etxtbsy")
#define efbig()           __ERRFUN("efbig")
#define enospc()          __ERRFUN("enospc")
#define espipe()          __ERRFUN("espipe")
#define erofs()           __ERRFUN("erofs")
#define emlink()          __ERRFUN("emlink")
#define epipe()           __ERRFUN("epipe")
#define edom()            __ERRFUN("edom")
#define erange()          __ERRFUN("erange")
#define edeadlk()         __ERRFUN("edeadlk")
#define enametoolong()    __ERRFUN("enametoolong")
#define enolck()          __ERRFUN("enolck")
#define enosys()          __ERRFUN("enosys")
#define enotempty()       __ERRFUN("enotempty")
#define eloop()           __ERRFUN("eloop")
#define enomsg()          __ERRFUN("enomsg")
#define eidrm()           __ERRFUN("eidrm")
#define echrng()          __ERRFUN("echrng")
#define el2nsync()        __ERRFUN("el2nsync")
#define el3hlt()          __ERRFUN("el3hlt")
#define el3rst()          __ERRFUN("el3rst")
#define elnrng()          __ERRFUN("elnrng")
#define eunatch()         __ERRFUN("eunatch")
#define enocsi()          __ERRFUN("enocsi")
#define el2hlt()          __ERRFUN("el2hlt")
#define ebade()           __ERRFUN("ebade")
#define ebadr()           __ERRFUN("ebadr")
#define exfull()          __ERRFUN("exfull")
#define enoano()          __ERRFUN("enoano")
#define ebadrqc()         __ERRFUN("ebadrqc")
#define ebadslt()         __ERRFUN("ebadslt")
#define enostr()          __ERRFUN("enostr")
#define enodata()         __ERRFUN("enodata")
#define etime()           __ERRFUN("etime")
#define enosr()           __ERRFUN("enosr")
#define enonet()          __ERRFUN("enonet")
#define enopkg()          __ERRFUN("enopkg")
#define eremote()         __ERRFUN("eremote")
#define enolink()         __ERRFUN("enolink")
#define eadv()            __ERRFUN("eadv")
#define esrmnt()          __ERRFUN("esrmnt")
#define ecomm()           __ERRFUN("ecomm")
#define eproto()          __ERRFUN("eproto")
#define emultihop()       __ERRFUN("emultihop")
#define edotdot()         __ERRFUN("edotdot")
#define ebadmsg()         __ERRFUN("ebadmsg")
#define eoverflow()       __ERRFUN("eoverflow")
#define enotuniq()        __ERRFUN("enotuniq")
#define ebadfd()          __ERRFUN("ebadfd")
#define eremchg()         __ERRFUN("eremchg")
#define elibacc()         __ERRFUN("elibacc")
#define elibbad()         __ERRFUN("elibbad")
#define elibscn()         __ERRFUN("elibscn")
#define elibmax()         __ERRFUN("elibmax")
#define elibexec()        __ERRFUN("elibexec")
#define eilseq()          __ERRFUN("eilseq")
#define erestart()        __ERRFUN("erestart")
#define estrpipe()        __ERRFUN("estrpipe")
#define eusers()          __ERRFUN("eusers")
#define enotsock()        __ERRFUN("enotsock")
#define edestaddrreq()    __ERRFUN("edestaddrreq")
#define emsgsize()        __ERRFUN("emsgsize")
#define eprototype()      __ERRFUN("eprototype")
#define enoprotoopt()     __ERRFUN("enoprotoopt")
#define eprotonosupport() __ERRFUN("eprotonosupport")
#define esocktnosupport() __ERRFUN("esocktnosupport")
#define eopnotsupp()      __ERRFUN("eopnotsupp")
#define epfnosupport()    __ERRFUN("epfnosupport")
#define eafnosupport()    __ERRFUN("eafnosupport")
#define eaddrinuse()      __ERRFUN("eaddrinuse")
#define eaddrnotavail()   __ERRFUN("eaddrnotavail")
#define enetdown()        __ERRFUN("enetdown")
#define enetunreach()     __ERRFUN("enetunreach")
#define enetreset()       __ERRFUN("enetreset")
#define econnaborted()    __ERRFUN("econnaborted")
#define econnreset()      __ERRFUN("econnreset")
#define enobufs()         __ERRFUN("enobufs")
#define eisconn()         __ERRFUN("eisconn")
#define enotconn()        __ERRFUN("enotconn")
#define eshutdown()       __ERRFUN("eshutdown")
#define etoomanyrefs()    __ERRFUN("etoomanyrefs")
#define etimedout()       __ERRFUN("etimedout")
#define econnrefused()    __ERRFUN("econnrefused")
#define ehostdown()       __ERRFUN("ehostdown")
#define ehostunreach()    __ERRFUN("ehostunreach")
#define ealready()        __ERRFUN("ealready")
#define einprogress()     __ERRFUN("einprogress")
#define estale()          __ERRFUN("estale")
#define euclean()         __ERRFUN("euclean")
#define enotnam()         __ERRFUN("enotnam")
#define enavail()         __ERRFUN("enavail")
#define eisnam()          __ERRFUN("eisnam")
#define eremoteio()       __ERRFUN("eremoteio")
#define edquot()          __ERRFUN("edquot")
#define enomedium()       __ERRFUN("enomedium")
#define emediumtype()     __ERRFUN("emediumtype")
#define ecanceled()       __ERRFUN("ecanceled")
#define enokey()          __ERRFUN("enokey")
#define ekeyexpired()     __ERRFUN("ekeyexpired")
#define ekeyrevoked()     __ERRFUN("ekeyrevoked")
#define ekeyrejected()    __ERRFUN("ekeyrejected")
#define eownerdead()      __ERRFUN("eownerdead")
#define enotrecoverable() __ERRFUN("enotrecoverable")
#define erfkill()         __ERRFUN("erfkill")
#define ehwpoison()       __ERRFUN("ehwpoison")

#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_SYSV_ERRFUNS_H_ */