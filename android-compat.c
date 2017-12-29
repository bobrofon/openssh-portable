#undef ANDROID
#include "android-compat.h"

#include <stddef.h>

static struct passwd android_root_passwd = {
	"root",
	"x",
	0,
	0,
	"root",
	".",
	"/system/bin/sh"
};

struct passwd *android_getpwuid(uid_t uid)
{
	struct passwd *pw = getpwuid(uid);
	if (pw)
	{
		return pw;
	}
	if (!uid)
	{
		return &android_root_passwd;
	}
	return NULL;
}
