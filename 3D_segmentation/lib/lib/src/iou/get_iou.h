
#ifndef GET_IOU_H
#define GET_IOU_H
#include <torch/serialize/tensor.h>
#include <ATen/cuda/CUDAContext.h>


//
void get_iou_cuda(int nInstance, int nProposal, int *proposals_idx, int *proposals_offset, long *instance_labels, int *instance_pointnum, float *proposals_iou);
void get_iou(at::Tensor proposals_idx_tensor, at::Tensor proposals_offset_tensor, at::Tensor instance_labels_tensor, at::Tensor instance_pointnum_tensor, at::Tensor proposals_iou_tensor, int nInstance, int nProposal);

#endif //GET_IOU_H