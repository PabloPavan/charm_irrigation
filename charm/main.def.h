


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::KA_2_closure : public SDAG::Closure {
      double x1;
      double x2;


      KA_2_closure() {
        init();
      }
      KA_2_closure(CkMigrateMessage*) {
        init();
      }
      double & getP0() { return x1;}
      double & getP1() { return x2;}
      void pup(PUP::er& __p) {
        __p | x1;
        __p | x2;
        packClosure(__p);
      }
      virtual ~KA_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(KA_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::POT_3_closure : public SDAG::Closure {
      double x;


      POT_3_closure() {
        init();
      }
      POT_3_closure(CkMigrateMessage*) {
        init();
      }
      double & getP0() { return x;}
      void pup(PUP::er& __p) {
        __p | x;
        packClosure(__p);
      }
      virtual ~POT_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(POT_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::solucao_4_closure : public SDAG::Closure {
      double qot;


      solucao_4_closure() {
        init();
      }
      solucao_4_closure(CkMigrateMessage*) {
        init();
      }
      double & getP0() { return qot;}
      void pup(PUP::er& __p) {
        __p | qot;
        packClosure(__p);
      }
      virtual ~solucao_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(solucao_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::terminado_5_closure : public SDAG::Closure {
      

      terminado_5_closure() {
        init();
      }
      terminado_5_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~terminado_5_closure() {
      }
      PUPable_decl(SINGLE_ARG(terminado_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numChares;
 */
extern int numChares;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numChares(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numChares;
}
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
sync double KA(double x1, double x2);
sync double POT(double x);
void solucao(double qot);
void terminado();
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Main::CProxy_Main(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      _call_Main_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}


void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double KA(double x1, double x2);
 */

double CProxy_Main::KA(double x1, double x2, const CkEntryOptions *impl_e_opts)
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
  CkMarshallMsg *impl_msg_typed_ret = (CkMarshallMsg *)CkRemoteCall(CkIndex_Main::idx_KA_marshall2(), impl_msg, &ckGetChareID());
  char *impl_buf_ret=impl_msg_typed_ret->msgBuf; 
  PUP::fromMem implPS(impl_buf_ret); 
  double retval; implPS|retval; 
  CkFreeMsg(impl_msg_typed_ret); 
  return retval; 
}

// Entry point registration function

int CkIndex_Main::reg_KA_marshall2() {
  int epidx = CkRegisterEp("KA(double x1, double x2)",
      _call_KA_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_KA_marshall2);

  return epidx;
}


void CkIndex_Main::_call_KA_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
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

void CkIndex_Main::_marshallmessagepup_KA_marshall2(PUP::er &implDestP,void *impl_msg) {
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
PUPable_def(SINGLE_ARG(Closure_Main::KA_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sync double POT(double x);
 */

double CProxy_Main::POT(double x, const CkEntryOptions *impl_e_opts)
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
  CkMarshallMsg *impl_msg_typed_ret = (CkMarshallMsg *)CkRemoteCall(CkIndex_Main::idx_POT_marshall3(), impl_msg, &ckGetChareID());
  char *impl_buf_ret=impl_msg_typed_ret->msgBuf; 
  PUP::fromMem implPS(impl_buf_ret); 
  double retval; implPS|retval; 
  CkFreeMsg(impl_msg_typed_ret); 
  return retval; 
}

// Entry point registration function

int CkIndex_Main::reg_POT_marshall3() {
  int epidx = CkRegisterEp("POT(double x)",
      _call_POT_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_POT_marshall3);

  return epidx;
}


void CkIndex_Main::_call_POT_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
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

void CkIndex_Main::_marshallmessagepup_POT_marshall3(PUP::er &implDestP,void *impl_msg) {
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
PUPable_def(SINGLE_ARG(Closure_Main::POT_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void solucao(double qot);
 */

void CProxy_Main::solucao(double qot, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: double qot
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|qot;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|qot;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_solucao_marshall4(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_solucao_marshall4(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_solucao_marshall4(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_solucao_marshall4() {
  int epidx = CkRegisterEp("solucao(double qot)",
      _call_solucao_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_solucao_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_solucao_marshall4);

  return epidx;
}


void CkIndex_Main::_call_solucao_marshall4(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double qot*/
  PUP::fromMem implP(impl_buf);
  double qot; implP|qot;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->solucao(qot);
}

int CkIndex_Main::_callmarshall_solucao_marshall4(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: double qot*/
  PUP::fromMem implP(impl_buf);
  double qot; implP|qot;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->solucao(qot);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_solucao_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double qot*/
  PUP::fromMem implP(impl_buf);
  double qot; implP|qot;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("qot");
  implDestP|qot;
}
PUPable_def(SINGLE_ARG(Closure_Main::solucao_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void terminado();
 */

void CProxy_Main::terminado(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_terminado_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_terminado_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_terminado_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_terminado_void() {
  int epidx = CkRegisterEp("terminado()",
      _call_terminado_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_terminado_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->terminado();
}
PUPable_def(SINGLE_ARG(Closure_Main::terminado_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: sync double KA(double x1, double x2);
  idx_KA_marshall2();

  // REG: sync double POT(double x);
  idx_POT_marshall3();

  // REG: void solucao(double qot);
  idx_solucao_marshall4();

  // REG: void terminado();
  idx_terminado_void();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registermain(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("numChares","int",sizeof(numChares),(void *) &numChares,__xlater_roPup_numChares);

  _registerIrrigacao();

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
sync double KA(double x1, double x2);
sync double POT(double x);
void solucao(double qot);
void terminado();
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

}
extern "C" void CkRegisterMainModule(void) {
  _registermain();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main >(dynamic_cast<Main* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
