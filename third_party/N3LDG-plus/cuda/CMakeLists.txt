set(CUDA_SEPARABLE_COMPILATION ON)
list(APPEND CUDA_NVCC_FLAGS "--use_fast_math;-arch=compute_61;-code=sm_61;-std=c++11;-DVERBOSE;-DEIGEN_USE_GPU;-DHAVE_CUDA;")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    list(APPEND CUDA_NVCC_FLAGS "-G")
    list(APPEND CUDA_NVCC_FLAGS "-g")
    list(APPEND CUDA_NVCC_FLAGS "-O1")
else()
    list(APPEND CUDA_NVCC_FLAGS "-O3")
endif()

SET(CUDA_PROPAGATE_HOST_FLAGS OFF)

CUDA_ADD_LIBRARY(n3ldg_cuda N3LDG_cuda.cu)
CUDA_ADD_CUBLAS_TO_TARGET(n3ldg_cuda)

TARGET_LINK_LIBRARIES(n3ldg_cuda cnmem)
SET(LIBS ${LIBS} n3ldg_cuda)
