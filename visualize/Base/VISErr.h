#ifndef __VISERR_H__
#define __VISERR_H__

#include <iostream>
#include <exception>

namespace vis {

  class viserr : public std::exception {
    
  public:
    viserr(std::string msg="") : std::exception()
    {
      _msg = "\033[93m";
      _msg += msg;
      _msg += "\033[00m";
    }

    virtual ~viserr() throw() {}
    virtual const char* what() const throw()
    { return _msg.c_str(); }

  private:
    std::string _msg;
    
  };
}

#endif
