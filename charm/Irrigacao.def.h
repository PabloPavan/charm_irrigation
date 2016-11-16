/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Irrigacao::worker_2_closure : public SDAG::Closure {
      int impl_noname_0;
      double impl_noname_1;
      double impl_noname_2;
      int impl_noname_3;
      int impl_noname_4;
      int impl_noname_5;


      worker_2_closure() {
        init();
      }
      worker_2_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return impl_noname_0;}
      double & getP1() { return impl_noname_1;}
      double & getP2() { return impl_noname_2;}
      int & getP3() { return impl_noname_3;}
      int & getP4() { return impl_noname_4;}
      int & getP5() { return impl_noname_5;}
      void pup(PUP::er& __p) {
        __p | impl_noname_0;
        __p | impl_noname_1;
        __p | impl_noname_2;
        __p | impl_noname_3;
        __p | impl_noname_4;
        __p | impl_noname_5;
        packClosure(__p);
      }
      virtual ~worker_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(worker_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Irrigacao::KA_3_closure : public SDAG::Closure {
      double x1;
      double x2;


      KA_3_closure() {
        init();
      }
      KA_3_closure(CkMigrateMessage*) {
        init();
      }
      double & getP0() { return x1;}
      double & getP1() { return x2;}
      void pup(PUP::er& __p) {
        __p | x1;
        __p | x2;
        packClosure(__p);
      }
      virtual ~KA_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(KA_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Irrigacao::POT_4_closure : public SDAG::Closure {
      double x;


      POT_4_closure() {
        init();
      }
      POT_4_closure(CkMigrateMessage*) {
        init();
      }
      double & getP0() { return x;}
      void pup(PUP::er& __p) {
        __p | x;
        packClosure(__p);
      }
      virtual ~POT_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(POT_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: array Irrigacao: ArrayElement{
Irrigacao();
void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
sync double KA(double x1, double x2);
sync double POT(double x);
Irrigacao(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Irrigacao::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao();
 */

void CProxyElement_Irrigacao::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
  void *impl_msg = CkAllocSysMsg();
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Irrigacao::idx_Irrigacao_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */

void CProxyElement_Irrigacao::worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Irrigacao::idx_worker_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double KA(double x1, double x2);
 */

double CProxyElement_Irrigacao::KA(double x1, double x2, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: double x1, double x2
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x1;
    implP|x2;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x1;
    implP|x2;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  CkMarshallMsg *impl_msg_typed_ret = (CkMarshallMsg *)ckSendSync(impl_amsg, CkIndex_Irrigacao::idx_KA_marshall3());
  char *impl_buf_ret=impl_msg_typed_ret->msgBuf; 
  PUP::fromMem implPS(impl_buf_ret); 
  double retval; implPS|retval; 
  CkFreeMsg(impl_msg_typed_ret); 
  return retval; 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double POT(double x);
 */

double CProxyElement_Irrigacao::POT(double x, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: double x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  CkMarshallMsg *impl_msg_typed_ret = (CkMarshallMsg *)ckSendSync(impl_amsg, CkIndex_Irrigacao::idx_POT_marshall4());
  char *impl_buf_ret=impl_msg_typed_ret->msgBuf; 
  PUP::fromMem implPS(impl_buf_ret); 
  double retval; implPS|retval; 
  CkFreeMsg(impl_msg_typed_ret); 
  return retval; 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao();
 */

CkArrayID CProxy_Irrigacao::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Irrigacao::idx_Irrigacao_void(), opts);
  return gId;
}

void CProxy_Irrigacao::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Irrigacao::idx_Irrigacao_void(), _ck_array_creation_cb, opts, impl_msg);
}

CkArrayID CProxy_Irrigacao::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Irrigacao::idx_Irrigacao_void(), opts);
  return gId;
}

void CProxy_Irrigacao::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Irrigacao::idx_Irrigacao_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function

int CkIndex_Irrigacao::reg_Irrigacao_void() {
  int epidx = CkRegisterEp("Irrigacao()",
      _call_Irrigacao_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Irrigacao::_call_Irrigacao_void(void* impl_msg, void* impl_obj_void)
{
  Irrigacao* impl_obj = static_cast<Irrigacao *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Irrigacao();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */

void CProxy_Irrigacao::worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Irrigacao::idx_worker_marshall2(),0);
}

// Entry point registration function

int CkIndex_Irrigacao::reg_worker_marshall2() {
  int epidx = CkRegisterEp("worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5)",
      _call_worker_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_worker_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_worker_marshall2);

  return epidx;
}


void CkIndex_Irrigacao::_call_worker_marshall2(void* impl_msg, void* impl_obj_void)
{
  Irrigacao* impl_obj = static_cast<Irrigacao *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5*/
  PUP::fromMem implP(impl_buf);
  int impl_noname_0; implP|impl_noname_0;
  double impl_noname_1; implP|impl_noname_1;
  double impl_noname_2; implP|impl_noname_2;
  int impl_noname_3; implP|impl_noname_3;
  int impl_noname_4; implP|impl_noname_4;
  int impl_noname_5; implP|impl_noname_5;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->worker(impl_noname_0, impl_noname_1, impl_noname_2, impl_noname_3, impl_noname_4, impl_noname_5);
}

int CkIndex_Irrigacao::_callmarshall_worker_marshall2(char* impl_buf, void* impl_obj_void) {
  Irrigacao* impl_obj = static_cast< Irrigacao *>(impl_obj_void);
  /*Unmarshall pup'd fields: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5*/
  PUP::fromMem implP(impl_buf);
  int impl_noname_0; implP|impl_noname_0;
  double impl_noname_1; implP|impl_noname_1;
  double impl_noname_2; implP|impl_noname_2;
  int impl_noname_3; implP|impl_noname_3;
  int impl_noname_4; implP|impl_noname_4;
  int impl_noname_5; implP|impl_noname_5;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->worker(impl_noname_0, impl_noname_1, impl_noname_2, impl_noname_3, impl_noname_4, impl_noname_5);
  return implP.size();
}

void CkIndex_Irrigacao::_marshallmessagepup_worker_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5*/
  PUP::fromMem implP(impl_buf);
  int impl_noname_0; implP|impl_noname_0;
  double impl_noname_1; implP|impl_noname_1;
  double impl_noname_2; implP|impl_noname_2;
  int impl_noname_3; implP|impl_noname_3;
  int impl_noname_4; implP|impl_noname_4;
  int impl_noname_5; implP|impl_noname_5;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_1");
  implDestP|impl_noname_1;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_2");
  implDestP|impl_noname_2;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_3");
  implDestP|impl_noname_3;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_4");
  implDestP|impl_noname_4;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_5");
  implDestP|impl_noname_5;
}
PUPable_def(SINGLE_ARG(Closure_Irrigacao::worker_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double KA(double x1, double x2);
 */

// Entry point registration function

int CkIndex_Irrigacao::reg_KA_marshall3() {
  int epidx = CkRegisterEp("KA(double x1, double x2)",
      _call_KA_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_KA_marshall3);

  return epidx;
}


void CkIndex_Irrigacao::_call_KA_marshall3(void* impl_msg, void* impl_obj_void)
{
  Irrigacao* impl_obj = static_cast<Irrigacao *>(impl_obj_void);
  int impl_ref = CkGetRefNum(impl_msg), impl_src = CkGetSrcPe(impl_msg);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double x1, double x2*/
  PUP::fromMem implP(impl_buf);
  double x1; implP|x1;
  double x2; implP|x2;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  double impl_ret_val=   impl_obj->KA(x1, x2);
  //Marshall: impl_ret_val
  int impl_ret_size=0;
  { //Find the size of the PUP'd data
    PUP::sizer implPS;
    implPS|impl_ret_val;
    impl_ret_size+=implPS.size();
  };
  CkMarshallMsg *impl_retMsg=CkAllocateMarshallMsg(impl_ret_size, NULL);
  { //Copy over the PUP'd data;
    PUP::toMem implPS((void *)impl_retMsg->msgBuf);
    implPS|impl_ret_val;
  };
  CkSendToFutureID(impl_ref, impl_retMsg, impl_src);
}

void CkIndex_Irrigacao::_marshallmessagepup_KA_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double x1, double x2*/
  PUP::fromMem implP(impl_buf);
  double x1; implP|x1;
  double x2; implP|x2;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("x1");
  implDestP|x1;
  if (implDestP.hasComments()) implDestP.comment("x2");
  implDestP|x2;
}
PUPable_def(SINGLE_ARG(Closure_Irrigacao::KA_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double POT(double x);
 */

// Entry point registration function

int CkIndex_Irrigacao::reg_POT_marshall4() {
  int epidx = CkRegisterEp("POT(double x)",
      _call_POT_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_POT_marshall4);

  return epidx;
}


void CkIndex_Irrigacao::_call_POT_marshall4(void* impl_msg, void* impl_obj_void)
{
  Irrigacao* impl_obj = static_cast<Irrigacao *>(impl_obj_void);
  int impl_ref = CkGetRefNum(impl_msg), impl_src = CkGetSrcPe(impl_msg);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double x*/
  PUP::fromMem implP(impl_buf);
  double x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  double impl_ret_val=   impl_obj->POT(x);
  //Marshall: impl_ret_val
  int impl_ret_size=0;
  { //Find the size of the PUP'd data
    PUP::sizer implPS;
    implPS|impl_ret_val;
    impl_ret_size+=implPS.size();
  };
  CkMarshallMsg *impl_retMsg=CkAllocateMarshallMsg(impl_ret_size, NULL);
  { //Copy over the PUP'd data;
    PUP::toMem implPS((void *)impl_retMsg->msgBuf);
    implPS|impl_ret_val;
  };
  CkSendToFutureID(impl_ref, impl_retMsg, impl_src);
}

void CkIndex_Irrigacao::_marshallmessagepup_POT_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double x*/
  PUP::fromMem implP(impl_buf);
  double x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("x");
  implDestP|x;
}
PUPable_def(SINGLE_ARG(Closure_Irrigacao::POT_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Irrigacao::reg_Irrigacao_CkMigrateMessage() {
  int epidx = CkRegisterEp("Irrigacao(CkMigrateMessage* impl_msg)",
      _call_Irrigacao_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Irrigacao::_call_Irrigacao_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Irrigacao* impl_obj = static_cast<Irrigacao *>(impl_obj_void);
  new (impl_obj) Irrigacao((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */

void CProxySection_Irrigacao::worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_noname_0;
    implP|impl_noname_1;
    implP|impl_noname_2;
    implP|impl_noname_3;
    implP|impl_noname_4;
    implP|impl_noname_5;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Irrigacao::idx_worker_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double KA(double x1, double x2);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double POT(double x);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Irrigacao(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Irrigacao::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Irrigacao();
  idx_Irrigacao_void();
  CkRegisterDefaultCtor(__idx, idx_Irrigacao_void());

  // REG: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
  idx_worker_marshall2();

  // REG: sync double KA(double x1, double x2);
  idx_KA_marshall3();

  // REG: sync double POT(double x);
  idx_POT_marshall4();

  // REG: Irrigacao(CkMigrateMessage* impl_msg);
  idx_Irrigacao_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Irrigacao_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerIrrigacao(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: array Irrigacao: ArrayElement{
Irrigacao();
void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
sync double KA(double x1, double x2);
sync double POT(double x);
Irrigacao(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Irrigacao::__register("Irrigacao", sizeof(Irrigacao));

}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Irrigacao::virtual_pup(PUP::er &p) {
    recursive_pup<Irrigacao >(dynamic_cast<Irrigacao* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
