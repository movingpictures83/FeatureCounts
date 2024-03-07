#ifndef FeatureCountsPLUGIN_H
#define FeatureCountsPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class FeatureCountsPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "FeatureCounts";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
