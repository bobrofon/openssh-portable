#ifndef ANDROIDCOMPAT_H
#define ANDROIDCOMPAT_H

#include <sys/types.h>
#include <pwd.h>

extern struct passwd *android_getpwuid(uid_t uid);

#ifdef ANDROID
#define getpwuid(uid) android_getpwuid(uid)
#endif

#endif // ANDROIDCOMPAT_H
