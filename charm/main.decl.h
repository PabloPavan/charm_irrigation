#ifndef _DECL_main_H_
#define _DECL_main_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: readonly int numChares;
 */

#include "Irrigacao.decl.h"

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
sync double KA(double x1, double x2);
sync double POT(double x);
void solucao(double qot);
void terminado();
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: sync double KA(double x1, double x2);
     */
    // Entry point registration at startup
    
    static int reg_KA_marshall2();
    // Entry point index lookup
    
    inline static int idx_KA_marshall2() {
      static int epidx = reg_KA_marshall2();
      return epidx;
    }

    
    inline static int idx_KA(double (Main::*)(double x1, double x2) ) {
      return idx_KA_marshall2();
    }


    
    static int KA(double x1, double x2) { return idx_KA_marshall2(); }
    
    static void _call_KA_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_KA_marshall2(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_KA_marshall2(PUP::er &p,void *msg);
    /* DECLS: sync double POT(double x);
     */
    // Entry point registration at startup
    
    static int reg_POT_marshall3();
    // Entry point index lookup
    
    inline static int idx_POT_marshall3() {
      static int epidx = reg_POT_marshall3();
      return epidx;
    }

    
    inline static int idx_POT(double (Main::*)(double x) ) {
      return idx_POT_marshall3();
    }


    
    static int POT(double x) { return idx_POT_marshall3(); }
    
    static void _call_POT_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_POT_marshall3(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_POT_marshall3(PUP::er &p,void *msg);
    /* DECLS: void solucao(double qot);
     */
    // Entry point registration at startup
    
    static int reg_solucao_marshall4();
    // Entry point index lookup
    
    inline static int idx_solucao_marshall4() {
      static int epidx = reg_solucao_marshall4();
      return epidx;
    }

    
    inline static int idx_solucao(void (Main::*)(double qot) ) {
      return idx_solucao_marshall4();
    }


    
    static int solucao(double qot) { return idx_solucao_marshall4(); }
    
    static void _call_solucao_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_solucao_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_solucao_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_solucao_marshall4(PUP::er &p,void *msg);
    /* DECLS: void terminado();
     */
    // Entry point registration at startup
    
    static int reg_terminado_void();
    // Entry point index lookup
    
    inline static int idx_terminado_void() {
      static int epidx = reg_terminado_void();
      return epidx;
    }

    
    inline static int idx_terminado(void (Main::*)() ) {
      return idx_terminado_void();
    }


    
    static int terminado() { return idx_terminado_void(); }
    
    static void _call_terminado_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_terminado_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Main(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: sync double KA(double x1, double x2);
 */
    
    double KA(double x1, double x2, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: sync double POT(double x);
 */
    
    double POT(double x, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void solucao(double qot);
 */
    
    void solucao(double qot, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void terminado();
 */
    
    void terminado(const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Main)
#define Main_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Main>CBase_Main;




/* ---------------- method closures -------------- */
class Closure_Main {
  public:


    struct KA_2_closure;


    struct POT_3_closure;


    struct solucao_4_closure;


    struct terminado_5_closure;

};

extern void _registermain(void);
extern "C" void CkRegisterMainModule(void);
#endif
