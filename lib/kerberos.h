#ifndef KERBEROS_H
#define KERBEROS_H

#include <gssapi/gssapi.h>
#include <gssapi/gssapi_generic.h>
#include <gssapi/gssapi_krb5.h>
#include <node.h>

#include <node_object_wrap.h>
#include <v8.h>
#include "nan.h"

extern "C" {
#include "kerberosgss.h"
}

using namespace v8;
using namespace node;

class Kerberos : public Nan::ObjectWrap {
   public:
    Kerberos();
    ~Kerberos(){};

    // Constructor used for creating new Kerberos objects from C++
    static Nan::Persistent<FunctionTemplate> constructor_template;

    // Initialize function for the object
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);

    // Method available
    static NAN_METHOD(AuthGSSClientInit);
    static NAN_METHOD(AuthGSSClientStep);
    static NAN_METHOD(AuthGSSClientUnwrap);
    static NAN_METHOD(AuthGSSClientWrap);
    static NAN_METHOD(AuthGSSClientClean);
    static NAN_METHOD(AuthGSSServerInit);
    static NAN_METHOD(AuthGSSServerClean);
    static NAN_METHOD(AuthGSSServerStep);
    static NAN_METHOD(AuthUserKrb5Password);

   private:
    static NAN_METHOD(New);
    // Handles the uv calls
    static void Process(uv_work_t* work_req);
    // Called after work is done
    static void After(uv_work_t* work_req);
};

#endif
