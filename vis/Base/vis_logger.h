#ifndef __VIS_LOGGER_H__
#define __VIS_LOGGER_H__

#include <cstdio>
#include <iostream>
#include <map>
#include "VISTypes.h"

namespace vis {

  class logger{
    
  public:
    
    /// Default constructor
    logger(const std::string& name="no_name")
      : _ostrm(&std::cout)
      , _name(name)
    {}
    
    /// Default destructor
    virtual ~logger(){};
    
  private:
    
    /// ostream
    std::ostream *_ostrm; //!
    
    /// Level
    msg::Level_t _level;
      
    /// Name
    std::string _name;
    
    /// Set of loggers
    static std::map<std::string,vis::logger> *_logger_m; 

    /// Shared logger
    static vis::logger* _shared_logger;

    /// Default logger level
    static msg::Level_t _level_default;
    
  public:

    /// Logger's name
    const std::string& name() const { return _name; }

    /// Verbosity level setter
    void set(const msg::Level_t level) { _level = level; }

    /// Verbosity level getter
    msg::Level_t level() const { return _level; }

    /// Comparison operator for static collection of loggers
    inline bool operator<(const logger& rhs) const
    {
      if(_name < rhs.name()) return true;
      if(_name > rhs.name()) return false;
      return false;
    }
    
    /// Getter of a message instance 
    static logger& get(const std::string name)
    {
      if(!_logger_m) _logger_m = new std::map<std::string,vis::logger>();
      auto iter = _logger_m->find(name);
      if(iter == _logger_m->end()) {
        iter = _logger_m->emplace(name,logger(name)).first;
        iter->second.set(msg::kNORMAL);
      }
      return iter->second;
    };

    static logger& get_shared();

    /// Default logger level getter
    static msg::Level_t default_level() { return _level_default; }
    /// Default logger level setter (only affect future loggers)
    static void default_level(msg::Level_t l) { _level_default = l; }
    /// Force all loggers to change level
    static void force_level(msg::Level_t l)
    {
      default_level(l);
      for(auto& name_logger : *_logger_m) name_logger.second.set(l);
    }
	
    //
    // Verbosity level checker
    //
    inline bool debug   () const { return _level <= msg::kDEBUG;   }
    inline bool info    () const { return _level <= msg::kINFO;    }
    inline bool normal  () const { return _level <= msg::kNORMAL;  }
    inline bool warning () const { return _level <= msg::kWARNING; }
    inline bool error   () const { return _level <= msg::kERROR;   }
    /// Formatted message (simplest)
    std::ostream& send(const msg::Level_t) const;
    /// Formatted message (function name included)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function ) const;
    /// Formatted message (function name + line number)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function,
		       const unsigned int line_num ) const;
    /// Formatted message (function name + line number + file name)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function,
		       const unsigned int line_num,
		       const std::string& file_name) const;
    
  };
}
//
// Compiler macro for saving us from text typing
//
/// Compiler macro for DEBUG message
#define SP_DEBUG()    if( logger().debug   () ) logger().send(::vis::msg::kDEBUG,    __FUNCTION__, __LINE__, __FILE__)
/// Compiler macro for INFO message
#define SP_INFO()     if( logger().info    () ) logger().send(::vis::msg::kINFO,     __FUNCTION__, __LINE__          )
/// Compiler macro for NORMAL message
#define SP_NORMAL()   if( logger().normal  () ) logger().send(::vis::msg::kNORMAL,   __FUNCTION__                    )
/// Compiler macro for WARNING message
#define SP_WARNING()  if( logger().warning () ) logger().send(::vis::msg::kWARNING,  __FUNCTION__                    )
/// Compiler macro for ERROR message
#define SP_ERROR()    if( logger().error   () ) logger().send(::vis::msg::kERROR,    __FUNCTION__, __LINE__          )
/// Compiler macro for CRITICAL message
#define SP_CRITICAL()                           logger().send(::vis::msg::kCRITICAL, __FUNCTION__, __LINE__, __FILE__)

#define SP_SDEBUG()    if(vis::logger::get_shared().debug())    vis::logger::get_shared().send(::vis::msg::kDEBUG,    __FUNCTION__,__LINE__,__FILE__)
#define SP_SINFO()     if(vis::logger::get_shared().info())     vis::logger::get_shared().send(::vis::msg::kINFO,     __FUNCTION__,__LINE__         )
#define SP_SNORMAL()   if(vis::logger::get_shared().normal())   vis::logger::get_shared().send(::vis::msg::kNORMAL,   __FUNCTION__                  )
#define SP_SWARNING()  if(vis::logger::get_shared().warning())  vis::logger::get_shared().send(::vis::msg::kWARNING,  __FUNCTION__                  )
#define SP_SERROR()    if(vis::logger::get_shared().error())    vis::logger::get_shared().send(::vis::msg::kERROR,    __FUNCTION__,__LINE__         )
#define SP_SCRITICAL() vis::logger::get_shared().send(::vis::msg::kCRITICAL, __FUNCTION__,__LINE__,__FILE__)
  
/** @} */ // end of doxygen group logger
#endif
