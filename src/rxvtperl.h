/*
 * rxvtperl.h
 */

#ifndef RXVTPERL_H_
#define RXVTPERL_H_

#if ENABLE_PERL

#include "rxvt.h"

#define PERL_INVOKE(args) rxvt_perl.invoke args

enum data_type {
  DT_END,
  DT_INT,
  DT_LONG,
};

enum hook_type {
  HOOK_LOAD,

  HOOK_INIT,
  HOOK_RESET,
  HOOK_START,
  HOOK_DESTROY,

  HOOK_SEL_BEGIN,
  HOOK_SEL_EXTEND,
  HOOK_SEL_MAKE,
  HOOK_SEL_GRAB,

  HOOK_FOCUS_IN,
  HOOK_FOCUS_OUT,

  HOOK_VIEW_CHANGE,
  HOOK_SCROLL_BACK,
  HOOK_TTY_ACTIVITY,

  HOOK_REFRESH_BEGIN,
  HOOK_REFRESH_END,

  HOOK_NUM,
};

struct rxvt_perl_interp
{
  rxvt_perl_interp ();
  ~rxvt_perl_interp ();

  bool should_invoke[HOOK_NUM];

  void init ();
  bool invoke (rxvt_term *term, hook_type htype, ...);
};

extern struct rxvt_perl_interp rxvt_perl;

#else
#define PERL_INVOKE(args) (void)0
#endif

#endif

