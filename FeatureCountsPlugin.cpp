#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FeatureCountsPlugin.h"

void FeatureCountsPlugin::input(std::string file) {
   readParameterFile(file);
}

void FeatureCountsPlugin::run() {}

void FeatureCountsPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 //featureCounts -T 8 -t exon -g gene_id -a hum37_2_1M.gtf -o gene_counts.txt ex1.bam
 myCommand += "featureCounts -T 8 -t exon -g gene_id -a "+PluginManager::addPrefix(myParameters["gtffile"])+" -o "+file+" "+PluginManager::addPrefix(myParameters["bamfile"]);
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<FeatureCountsPlugin> FeatureCountsPluginProxy = PluginProxy<FeatureCountsPlugin>("FeatureCounts", PluginManager::getInstance());
