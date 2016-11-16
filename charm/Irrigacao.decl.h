#ifndef _DECL_Irrigacao_H_
#define _DECL_Irrigacao_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: array Irrigacao: ArrayElement{
Irrigacao();
void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
sync double KA(double x1, double x2);
sync double POT(double x);
Irrigacao(CkMigrateMessage* impl_msg);
};
 */
 class Irrigacao;
 class CkIndex_Irrigacao;
 class CProxy_Irrigacao;
 class CProxyElement_Irrigacao;
 class CProxySection_Irrigacao;
/* --------------- index object ------------------ */
class CkIndex_Irrigacao:public CkIndex_ArrayElement{
  public:
    typedef Irrigacao local_t;
    typedef CkIndex_Irrigacao index_t;
    typedef CProxy_Irrigacao proxy_t;
    typedef CProxyElement_Irrigacao element_t;
    typedef CProxySection_Irrigacao section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Irrigacao();
     */
    // Entry point registration at startup
    
    static int reg_Irrigacao_void();
    // Entry point index lookup
    
    inline static int idx_Irrigacao_void() {
      static int epidx = reg_Irrigacao_void();
      return epidx;
    }

    
    static int ckNew() { return idx_Irrigacao_void(); }
    
    static void _call_Irrigacao_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Irrigacao_void(void* impl_msg, void* impl_obj);
    /* DECLS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
     */
    // Entry point registration at startup
    
    static int reg_worker_marshall2();
    // Entry point index lookup
    
    inline static int idx_worker_marshall2() {
      static int epidx = reg_worker_marshall2();
      return epidx;
    }

    
    inline static int idx_worker(void (Irrigacao::*)(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5) ) {
      return idx_worker_marshall2();
    }


    
    static int worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5) { return idx_worker_marshall2(); }
    
    static void _call_worker_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_worker_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_worker_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_worker_marshall2(PUP::er &p,void *msg);
    /* DECLS: sync double KA(double x1, double x2);
     */
    // Entry point registration at startup
    
    static int reg_KA_marshall3();
    // Entry point index lookup
    
    inline static int idx_KA_marshall3() {
      static int epidx = reg_KA_marshall3();
      return epidx;
    }

    
    inline static int idx_KA(double (Irrigacao::*)(double x1, double x2) ) {
      return idx_KA_marshall3();
    }


    
    static int KA(double x1, double x2) { return idx_KA_marshall3(); }
    
    static void _call_KA_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_KA_marshall3(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_KA_marshall3(PUP::er &p,void *msg);
    /* DECLS: sync double POT(double x);
     */
    // Entry point registration at startup
    
    static int reg_POT_marshall4();
    // Entry point index lookup
    
    inline static int idx_POT_marshall4() {
      static int epidx = reg_POT_marshall4();
      return epidx;
    }

    
    inline static int idx_POT(double (Irrigacao::*)(double x) ) {
      return idx_POT_marshall4();
    }


    
    static int POT(double x) { return idx_POT_marshall4(); }
    
    static void _call_POT_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_POT_marshall4(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_POT_marshall4(PUP::er &p,void *msg);
    /* DECLS: Irrigacao(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Irrigacao_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Irrigacao_CkMigrateMessage() {
      static int epidx = reg_Irrigacao_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Irrigacao_CkMigrateMessage(); }
    
    static void _call_Irrigacao_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Irrigacao_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Irrigacao : public CProxyElement_ArrayElement{
  public:
    typedef Irrigacao local_t;
    typedef CkIndex_Irrigacao index_t;
    typedef CProxy_Irrigacao proxy_t;
    typedef CProxyElement_Irrigacao element_t;
    typedef CProxySection_Irrigacao section_t;


    /* TRAM aggregators */

    CProxyElement_Irrigacao(void) {
    }
    CProxyElement_Irrigacao(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Irrigacao *ckLocal(void) const
    { return (Irrigacao *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Irrigacao(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Irrigacao(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Irrigacao(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Irrigacao(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Irrigacao();
 */
    
    void insert(int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */
    
    void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: sync double KA(double x1, double x2);
 */
    
    double KA(double x1, double x2, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: sync double POT(double x);
 */
    
    double POT(double x, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Irrigacao(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxyElement_Irrigacao)
/* ---------------- collective proxy -------------- */
 class CProxy_Irrigacao : public CProxy_ArrayElement{
  public:
    typedef Irrigacao local_t;
    typedef CkIndex_Irrigacao index_t;
    typedef CProxy_Irrigacao proxy_t;
    typedef CProxyElement_Irrigacao element_t;
    typedef CProxySection_Irrigacao section_t;

    CProxy_Irrigacao(void) {
    }
    CProxy_Irrigacao(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Generalized array indexing:
    CProxyElement_Irrigacao operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Irrigacao(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Irrigacao operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Irrigacao(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Irrigacao operator [] (int idx) const 
        {return CProxyElement_Irrigacao(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Irrigacao operator () (int idx) const 
        {return CProxyElement_Irrigacao(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Irrigacao(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Irrigacao(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Irrigacao();
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */
    
    void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: sync double KA(double x1, double x2);
 */

/* DECLS: sync double POT(double x);
 */

/* DECLS: Irrigacao(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxy_Irrigacao)
/* ---------------- section proxy -------------- */
 class CProxySection_Irrigacao : public CProxySection_ArrayElement{
  public:
    typedef Irrigacao local_t;
    typedef CkIndex_Irrigacao index_t;
    typedef CProxy_Irrigacao proxy_t;
    typedef CProxyElement_Irrigacao element_t;
    typedef CProxySection_Irrigacao section_t;

    CProxySection_Irrigacao(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Irrigacao operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Irrigacao(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Irrigacao operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Irrigacao(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Irrigacao operator [] (int idx) const 
        {return CProxyElement_Irrigacao(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Irrigacao operator () (int idx) const 
        {return CProxyElement_Irrigacao(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s) {
      CkVec<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.push_back(CkArrayIndex1D(i));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Irrigacao(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Irrigacao(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Irrigacao(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Irrigacao(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Irrigacao(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Irrigacao();
 */
    

/* DECLS: void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5);
 */
    
    void worker(int impl_noname_0, double impl_noname_1, double impl_noname_2, int impl_noname_3, int impl_noname_4, int impl_noname_5, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: sync double KA(double x1, double x2);
 */

/* DECLS: sync double POT(double x);
 */

/* DECLS: Irrigacao(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxySection_Irrigacao)
#define Irrigacao_SDAG_CODE 
typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Irrigacao>CBase_Irrigacao;

/* ---------------- method closures -------------- */
class Closure_Irrigacao {
  public:


    struct worker_2_closure;


    struct KA_3_closure;


    struct POT_4_closure;


};

extern void _registerIrrigacao(void);
#endif
