// Author: Mingcheng Chen (linyufly@gmail.com)
//
// The kdtree_test is modified from the source at
// http://pointclouds.org/documentation/tutorials/kdtree_search.php

#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <vector>

#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

void kdtree_test() {
  printf("kdtree_test {\n");
  srand(time(NULL));

  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  // Generate pointcloud data
  cloud->width = 1000;
  cloud->height = 1;
  cloud->points.resize(cloud->width * cloud->height);

  for (size_t i = 0; i < cloud->points.size (); ++i) {
    cloud->points[i].x = 1024.0f * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024.0f * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024.0f * rand () / (RAND_MAX + 1.0f);
  }

  pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;

  kdtree.setInputCloud (cloud);

  pcl::PointXYZ searchPoint;

  searchPoint.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
  searchPoint.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
  searchPoint.z = 1024.0f * rand () / (RAND_MAX + 1.0f);

  // K nearest neighbor search

  int K = 10;

  std::vector<int> pointIdxNKNSearch(K);
  std::vector<float> pointNKNSquaredDistance(K);

  printf("K nearest neighbor search at (%lf %lf %lf) with K=%d\n",
         searchPoint.x, searchPoint.y, searchPoint.z, K);

  if (kdtree.nearestKSearch(
      searchPoint, K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0) {
    for (size_t i = 0; i < pointIdxNKNSearch.size (); ++i) {
      printf("    %lf %lf %lf (squared distance: %lf)\n",
             cloud->points[pointIdxNKNSearch[i]].x,
             cloud->points[pointIdxNKNSearch[i]].y,
             cloud->points[pointIdxNKNSearch[i]].z,
             pointNKNSquaredDistance[i]);
    }
  }

  // Neighbors within radius search

  std::vector<int> pointIdxRadiusSearch;
  std::vector<float> pointRadiusSquaredDistance;

  float radius = 256.0f * rand () / (RAND_MAX + 1.0f);

  printf("Neighbors within radius search at (%lf %lf %lf) with radius=%lf\n",
         searchPoint.x, searchPoint.y, searchPoint.z, radius);

  if (kdtree.radiusSearch(
      searchPoint, radius, pointIdxRadiusSearch,
      pointRadiusSquaredDistance) > 0) {
    for (size_t i = 0; i < pointIdxRadiusSearch.size (); ++i) {
      printf("    %lf %lf %lf (squared distance: %lf)\n",
             cloud->points[pointIdxRadiusSearch[i]].x,
             cloud->points[pointIdxRadiusSearch[i]].y,
             cloud->points[pointIdxRadiusSearch[i]].z, 
             pointRadiusSquaredDistance[i]);
    }
  }

  printf("} kdtree_test\n");
  printf("\n");
}

int main() {
  kdtree_test();

  return 0;
}
