#include "constants.h"

#ifdef __APPLE__
#include <PCSC/winscard.h>
#include <PCSC/wintypes.h>
#else
#include <winscard.h>
#endif

void initConstants(v8::Local<v8::Object> target) {
	// TERMINAL and GLOBAL are not defined on Windows as per
	// https://docs.microsoft.com/windows/win32/api/winscard/nf-winscard-scardestablishcontext

	Nan::Set(target, Nan::New("SCARD_SCOPE_USER").ToLocalChecked(), Nan::New(SCARD_SCOPE_USER));

#ifdef WIN32
	Nan::Set(target, Nan::New("SCARD_SCOPE_TERMINAL").ToLocalChecked(), Nan::New(SCARD_SCOPE_USER));
#else
	Nan::Set(target, Nan::New("SCARD_SCOPE_TERMINAL").ToLocalChecked(), Nan::New(SCARD_SCOPE_TERMINAL));
#endif /* WIN32 */

	Nan::Set(target, Nan::New("SCARD_SCOPE_SYSTEM").ToLocalChecked(), Nan::New(SCARD_SCOPE_SYSTEM));

#ifdef WIN32
	Nan::Set(target, Nan::New("SCARD_SCOPE_GLOBAL").ToLocalChecked(), Nan::New(SCARD_SCOPE_SYSTEM));
#else
	Nan::Set(target, Nan::New("SCARD_SCOPE_GLOBAL").ToLocalChecked(), Nan::New(SCARD_SCOPE_GLOBAL));
#endif /* WIN32 */

}
