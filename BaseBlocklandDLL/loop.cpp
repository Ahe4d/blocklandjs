#pragma once
#include "uv8.h"

using namespace v8;

uv8_efunc(uv8_run) {
	uv8_unfinished_args();
}

uv8_efunc(uv8_walk) {
	uv8_unfinished_args();
}

Handle<ObjectTemplate> uv8_bind_loop(Isolate* this_) {
	Handle<ObjectTemplate> loop = ObjectTemplate::New(this_);
	loop->Set(this_, "run", FunctionTemplate::New(this_, uv8_run));
	loop->Set(this_, "walk", FunctionTemplate::New(this_, uv8_walk));

	return loop;
}