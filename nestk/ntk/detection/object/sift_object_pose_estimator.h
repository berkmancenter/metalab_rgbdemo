//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//

#ifndef SIFTOBJECTPOSEESTIMATOR_H
#define SIFTOBJECTPOSEESTIMATOR_H

#include <ntk/core.h>

#include "object_pose.h"
#include "sift_point_match.h"

namespace ntk
{

  class ObjectDetectorData;
  class SiftParameters;

  class SiftObjectPoseEstimator
  {
  public:
    SiftObjectPoseEstimator(const SiftParameters& params) : m_params(params) {}

  public:
    bool optimize(ObjectPose& pose,
                  SiftPointMatchConstPtrSet& matches,
                  const ObjectDetectorData& finder_data);

    bool computeFastPose(ObjectPose& pose,
                         SiftPointMatchConstPtrSet& matches,
                         const ObjectDetectorData& finder_data);

  private:
    const SiftParameters& m_params;
  };

} // avs

#endif // SIFTOBJECTPOSEESTIMATOR_H
