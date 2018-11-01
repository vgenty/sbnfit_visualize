#ifndef __VIS_BASE_H__
#define __VIS_BASE_H__

#include <vector>
#include "vis_logger.h"

namespace vis {
    
  class vis_base {
    
  public:
    
    vis_base(const std::string logger_name="vis_base")
      : _logger(nullptr)
    { _logger = &(::vis::logger::get(logger_name)); }
    
    vis_base(const vis_base &original) : _logger(original._logger) {}
    
    virtual ~vis_base(){};

    inline const vis::logger& logger() const
    { return *_logger; }
    
    void set_verbosity(::vis::msg::Level_t level)
    { _logger->set(level); }

    const std::string& name() const
    { return logger().name(); }
    
  private:
    
    vis::logger *_logger;   //! don't save
    
  };
}
#endif
