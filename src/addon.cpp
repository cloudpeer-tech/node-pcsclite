#include "pcsclite.h"
#include "cardreader.h"
#include "constants.h"

void init_all(v8::Local<v8::Object> target) {
    PCSCLite::init(target);
    CardReader::init(target);
	initConstants(target);
}

NODE_MODULE(pcsclite, init_all)
