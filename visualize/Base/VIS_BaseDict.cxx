// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME VIS_BaseDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "VISErr.h"
#include "LoadVIS.h"
#include "vis_logger.h"
#include "PyVIS.h"
#include "vis_base.h"
#include "VISTypes.h"

// Header files passed via #pragma extra_include

namespace vis {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *vis_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("vis", 0 /*version*/, "VISErr.h", 7,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &vis_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *vis_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace vis {
   namespace msg {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *viscLcLmsg_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("vis::msg", 0 /*version*/, "VISTypes.h", 30,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &viscLcLmsg_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *viscLcLmsg_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static TClass *viscLcLviserr_Dictionary();
   static void viscLcLviserr_TClassManip(TClass*);
   static void *new_viscLcLviserr(void *p = 0);
   static void *newArray_viscLcLviserr(Long_t size, void *p);
   static void delete_viscLcLviserr(void *p);
   static void deleteArray_viscLcLviserr(void *p);
   static void destruct_viscLcLviserr(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::vis::viserr*)
   {
      ::vis::viserr *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::vis::viserr));
      static ::ROOT::TGenericClassInfo 
         instance("vis::viserr", "VISErr.h", 9,
                  typeid(::vis::viserr), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &viscLcLviserr_Dictionary, isa_proxy, 4,
                  sizeof(::vis::viserr) );
      instance.SetNew(&new_viscLcLviserr);
      instance.SetNewArray(&newArray_viscLcLviserr);
      instance.SetDelete(&delete_viscLcLviserr);
      instance.SetDeleteArray(&deleteArray_viscLcLviserr);
      instance.SetDestructor(&destruct_viscLcLviserr);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::vis::viserr*)
   {
      return GenerateInitInstanceLocal((::vis::viserr*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::vis::viserr*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *viscLcLviserr_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::vis::viserr*)0x0)->GetClass();
      viscLcLviserr_TClassManip(theClass);
   return theClass;
   }

   static void viscLcLviserr_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *viscLcLLoadVIS_Dictionary();
   static void viscLcLLoadVIS_TClassManip(TClass*);
   static void *new_viscLcLLoadVIS(void *p = 0);
   static void *newArray_viscLcLLoadVIS(Long_t size, void *p);
   static void delete_viscLcLLoadVIS(void *p);
   static void deleteArray_viscLcLLoadVIS(void *p);
   static void destruct_viscLcLLoadVIS(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::vis::LoadVIS*)
   {
      ::vis::LoadVIS *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::vis::LoadVIS));
      static ::ROOT::TGenericClassInfo 
         instance("vis::LoadVIS", "LoadVIS.h", 5,
                  typeid(::vis::LoadVIS), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &viscLcLLoadVIS_Dictionary, isa_proxy, 4,
                  sizeof(::vis::LoadVIS) );
      instance.SetNew(&new_viscLcLLoadVIS);
      instance.SetNewArray(&newArray_viscLcLLoadVIS);
      instance.SetDelete(&delete_viscLcLLoadVIS);
      instance.SetDeleteArray(&deleteArray_viscLcLLoadVIS);
      instance.SetDestructor(&destruct_viscLcLLoadVIS);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::vis::LoadVIS*)
   {
      return GenerateInitInstanceLocal((::vis::LoadVIS*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::vis::LoadVIS*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *viscLcLLoadVIS_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::vis::LoadVIS*)0x0)->GetClass();
      viscLcLLoadVIS_TClassManip(theClass);
   return theClass;
   }

   static void viscLcLLoadVIS_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *viscLcLlogger_Dictionary();
   static void viscLcLlogger_TClassManip(TClass*);
   static void *new_viscLcLlogger(void *p = 0);
   static void *newArray_viscLcLlogger(Long_t size, void *p);
   static void delete_viscLcLlogger(void *p);
   static void deleteArray_viscLcLlogger(void *p);
   static void destruct_viscLcLlogger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::vis::logger*)
   {
      ::vis::logger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::vis::logger));
      static ::ROOT::TGenericClassInfo 
         instance("vis::logger", "vis_logger.h", 11,
                  typeid(::vis::logger), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &viscLcLlogger_Dictionary, isa_proxy, 4,
                  sizeof(::vis::logger) );
      instance.SetNew(&new_viscLcLlogger);
      instance.SetNewArray(&newArray_viscLcLlogger);
      instance.SetDelete(&delete_viscLcLlogger);
      instance.SetDeleteArray(&deleteArray_viscLcLlogger);
      instance.SetDestructor(&destruct_viscLcLlogger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::vis::logger*)
   {
      return GenerateInitInstanceLocal((::vis::logger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::vis::logger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *viscLcLlogger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::vis::logger*)0x0)->GetClass();
      viscLcLlogger_TClassManip(theClass);
   return theClass;
   }

   static void viscLcLlogger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *viscLcLvis_base_Dictionary();
   static void viscLcLvis_base_TClassManip(TClass*);
   static void *new_viscLcLvis_base(void *p = 0);
   static void *newArray_viscLcLvis_base(Long_t size, void *p);
   static void delete_viscLcLvis_base(void *p);
   static void deleteArray_viscLcLvis_base(void *p);
   static void destruct_viscLcLvis_base(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::vis::vis_base*)
   {
      ::vis::vis_base *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::vis::vis_base));
      static ::ROOT::TGenericClassInfo 
         instance("vis::vis_base", "vis_base.h", 9,
                  typeid(::vis::vis_base), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &viscLcLvis_base_Dictionary, isa_proxy, 4,
                  sizeof(::vis::vis_base) );
      instance.SetNew(&new_viscLcLvis_base);
      instance.SetNewArray(&newArray_viscLcLvis_base);
      instance.SetDelete(&delete_viscLcLvis_base);
      instance.SetDeleteArray(&deleteArray_viscLcLvis_base);
      instance.SetDestructor(&destruct_viscLcLvis_base);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::vis::vis_base*)
   {
      return GenerateInitInstanceLocal((::vis::vis_base*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::vis::vis_base*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *viscLcLvis_base_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::vis::vis_base*)0x0)->GetClass();
      viscLcLvis_base_TClassManip(theClass);
   return theClass;
   }

   static void viscLcLvis_base_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_viscLcLviserr(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::viserr : new ::vis::viserr;
   }
   static void *newArray_viscLcLviserr(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::viserr[nElements] : new ::vis::viserr[nElements];
   }
   // Wrapper around operator delete
   static void delete_viscLcLviserr(void *p) {
      delete ((::vis::viserr*)p);
   }
   static void deleteArray_viscLcLviserr(void *p) {
      delete [] ((::vis::viserr*)p);
   }
   static void destruct_viscLcLviserr(void *p) {
      typedef ::vis::viserr current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::vis::viserr

namespace ROOT {
   // Wrappers around operator new
   static void *new_viscLcLLoadVIS(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::LoadVIS : new ::vis::LoadVIS;
   }
   static void *newArray_viscLcLLoadVIS(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::LoadVIS[nElements] : new ::vis::LoadVIS[nElements];
   }
   // Wrapper around operator delete
   static void delete_viscLcLLoadVIS(void *p) {
      delete ((::vis::LoadVIS*)p);
   }
   static void deleteArray_viscLcLLoadVIS(void *p) {
      delete [] ((::vis::LoadVIS*)p);
   }
   static void destruct_viscLcLLoadVIS(void *p) {
      typedef ::vis::LoadVIS current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::vis::LoadVIS

namespace ROOT {
   // Wrappers around operator new
   static void *new_viscLcLlogger(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::logger : new ::vis::logger;
   }
   static void *newArray_viscLcLlogger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::logger[nElements] : new ::vis::logger[nElements];
   }
   // Wrapper around operator delete
   static void delete_viscLcLlogger(void *p) {
      delete ((::vis::logger*)p);
   }
   static void deleteArray_viscLcLlogger(void *p) {
      delete [] ((::vis::logger*)p);
   }
   static void destruct_viscLcLlogger(void *p) {
      typedef ::vis::logger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::vis::logger

namespace ROOT {
   // Wrappers around operator new
   static void *new_viscLcLvis_base(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::vis_base : new ::vis::vis_base;
   }
   static void *newArray_viscLcLvis_base(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::vis::vis_base[nElements] : new ::vis::vis_base[nElements];
   }
   // Wrapper around operator delete
   static void delete_viscLcLvis_base(void *p) {
      delete ((::vis::vis_base*)p);
   }
   static void deleteArray_viscLcLvis_base(void *p) {
      delete [] ((::vis::vis_base*)p);
   }
   static void destruct_viscLcLvis_base(void *p) {
      typedef ::vis::vis_base current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::vis::vis_base

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 214,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 214,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace {
  void TriggerDictionaryInitialization_libVIS_Base_Impl() {
    static const char* headers[] = {
"VISErr.h",
"LoadVIS.h",
"vis_logger.h",
"PyVIS.h",
"vis_base.h",
"VISTypes.h",
0
    };
    static const char* includePaths[] = {
"/data/vgenty/sw/sbnfit_visualizer/visualize",
"/data/vgenty/sw/virtualenv/venv/include/python2.7",
"/data/vgenty/sw/virtualenv/venv/include/python2.7",
"/data/vgenty/sw/virtualenv/venv/lib/python2.7/site-packages/numpy/core/include",
"/usr/nevis/sl7/root-6.08.06/include",
"/a/apps/local/sl7/root-6.08.06/include",
"/data/vgenty/sw/sbnfit_visualizer/visualize/Base/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libVIS_Base dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace vis{class __attribute__((annotate("$clingAutoload$VISErr.h")))  viserr;}
namespace vis{class __attribute__((annotate("$clingAutoload$LoadVIS.h")))  LoadVIS;}
namespace vis{class __attribute__((annotate("$clingAutoload$vis_logger.h")))  logger;}
namespace vis{class __attribute__((annotate("$clingAutoload$vis_base.h")))  vis_base;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libVIS_Base dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "VISErr.h"
#include "LoadVIS.h"
#include "vis_logger.h"
#include "PyVIS.h"
#include "vis_base.h"
#include "VISTypes.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"vis::LoadVIS", payloadCode, "@",
"vis::logger", payloadCode, "@",
"vis::vis_base", payloadCode, "@",
"vis::viserr", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libVIS_Base",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libVIS_Base_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libVIS_Base_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libVIS_Base() {
  TriggerDictionaryInitialization_libVIS_Base_Impl();
}
