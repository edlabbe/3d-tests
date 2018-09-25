#include <iostream>

#include <boost/make_shared.hpp>
#include <boost/format.hpp>

#include <pcl/console/parse.h>
#include <pcl/console/print.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/io.h>

#include "factory/edge_weight_computer_factory.h"
#include "factory/graph_builder_factory.h"

#include "random_walker_segmentation.h"

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZRGBNormal PointWithNormalT;
typedef pcl::Normal NormalT;

typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointCloud<PointWithNormalT> PointWithNormalCloudT;
typedef pcl::PointCloud<NormalT> NormalCloudT;

typedef typename pcl::segmentation::RandomWalkerSegmentation<pcl::PointXYZRGB>::Graph Graph;
typedef typename pcl::segmentation::RandomWalkerSegmentation<pcl::PointXYZRGB>::GraphPtr GraphPtr;

int main(int argc, char** argv) 
{
    std::cout << "Program Start\n";

    factory::EdgeWeightComputerFactory<Graph> wc_factory;
    factory::GraphBuilderFactory<PointWithNormalT, Graph> gb_factory;

    if (argc < 2 || pcl::console::find_switch (argc, argv, "--help"))
    {
        pcl::console::print_error ("Usage: %s <pcd-file>\n"
                                "--save-seeds <pcd-file>\n"
                                "--load-seeds <pcd-file>\n"
                                "--save\n"
                                "--save-clusters\n"
                                "--potential\n"
                                "--fixed-colors\n"
                                "%s\n"
                                "%s\n"
                                , argv[0]
                                , wc_factory.getUsage ().c_str ()
                                , gb_factory.getUsage ().c_str ());
        return (1);
    }
}
