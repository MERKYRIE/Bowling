// Copyright (c) 2008  INRIA Sophia-Antipolis (France), ETH Zurich (Switzerland).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v5.6/Intersections_3/include/CGAL/Intersections_3/internal/Bbox_3_Sphere_3_do_intersect.h $
// $Id: Bbox_3_Sphere_3_do_intersect.h 3a4e230 2022-11-22T12:22:42+01:00 Mael Rouxel-Labbé
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Camille Wormser, Jane Tournois, Pierre Alliez


#ifndef CGAL_INTERNAL_INTERSECTIONS_3_BBOX_3_SPHERE_3_DO_INTERSECT_H
#define CGAL_INTERNAL_INTERSECTIONS_3_BBOX_3_SPHERE_3_DO_INTERSECT_H

#include <../CGALOSP/Intersections_3/internal/Iso_cuboid_3_Sphere_3_do_intersect.h>

#include <../CGALOSP/Bbox_3.h>

namespace CGAL {
namespace Intersections {
namespace internal {

template <class K>
typename K::Boolean
do_intersect(const typename K::Sphere_3& sphere,
             const CGAL::Bbox_3& bbox,
             const K& k)
{
  return do_intersect_sphere_box_3(sphere,
                                   bbox.xmin(), bbox.ymin(), bbox.zmin(),
                                   bbox.xmax(), bbox.ymax(), bbox.zmax(),
                                   k);
}

template <class K>
typename K::Boolean
do_intersect(const CGAL::Bbox_3& bbox,
             const typename K::Sphere_3& sphere,
             const K& k)
{
  return do_intersect(sphere, bbox, k);
}

} // namespace internal
} // namespace Intersections
} // namespace CGAL

#endif // CGAL_INTERNAL_INTERSECTIONS_3_BBOX_3_SPHERE_3_DO_INTERSECT_H
