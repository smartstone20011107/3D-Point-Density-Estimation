[ICONIP2024] 3D Point Cloud Instance Segmentation Based on Cluster Density Estimation. 
This code could be run on RTX8000 RTX3090 RTX2080TI etc. with CUDA11.x and CUDA 10.X. Below we take RTX3090 environments as an example. You need at least two RTX3090 cards with 24GB.

#Creat Conda Environment
conda create -n net python=3.8
conda activate  net
Install MinkowskiEngine
conda install -c pytorch -c nvidia -c conda-forge pytorch=1.9.0 cudatoolkit=11.1 torchvision
conda install openblas-devel -c anaconda

# Uncomment the following line to specify the cuda home. Make sure `$CUDA_HOME/nvcc --version` is 11.X
# export CUDA_HOME=/usr/local/cuda-11.1
pip install -U git+https://github.com/NVIDIA/MinkowskiEngine -v --no-deps --install-option="--blas_include_dirs=${CONDA_PREFIX}/include" --install-option="--blas=openblas"

# Or if you want local MinkowskiEngine
cd lib
git clone https://github.com/NVIDIA/MinkowskiEngine.git
cd MinkowskiEngine
python setup.py install --blas_include_dirs=${CONDA_PREFIX}/include --blas=openblas
Install Our  _lib
pip install -r requirements
cd lib/ _lib
python setup.py develop
Install segmentator
cd lib/segmentator
cd csrc && mkdir build && cd build
conda install cmake cudnn

cmake .. \
-DCMAKE_PREFIX_PATH=`python -c 'import torch;print(torch.utils.cmake_prefix_path)'` \
-DPYTHON_INCLUDE_DIR=$(python -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())")  \
-DPYTHON_LIBRARY=$(python -c "import distutils.sysconfig as sysconfig; print(sysconfig.get_config_var('LIBDIR'))") \
-DCMAKE_INSTALL_PREFIX=`python -c 'from distutils.sysconfig import get_python_lib; print(get_python_lib())'`

make && make install # after install, please do not delete this folder (as we only create a symbolic link)
