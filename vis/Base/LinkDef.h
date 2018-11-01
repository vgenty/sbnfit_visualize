#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class std::string+;
#pragma link C++ class std::set<std::string>+;
#pragma link C++ class std::vector<std::string>+;
#pragma link C++ class std::vector<double>+;

#pragma link C++ namespace vis+;
#pragma link C++ class vis::LoadVIS+;
#pragma link C++ namespace vis::msg+;
#pragma link C++ enum vis::msg::Level_t+;
#pragma link C++ class vis::logger+;
#pragma link C++ class vis::vis_base+;
#pragma link C++ class vis::viserr+;

#endif
